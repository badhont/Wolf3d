/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:35:24 by badhont           #+#    #+#             */
/*   Updated: 2019/03/27 18:22:38 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_put_column(t_thrd *thrd, double wall_height, int x)
{
	int		p1;
	int		p2;
	int		y;

	y = -1;
	p1 = YDIM / 2 - wall_height / 2;
	p2 = YDIM - p1;
	while (++y < YDIM)
	{
		if (y < p1)
		{
			(thrd->env->tex.which_tex == 2)
				? ft_setpixel(thrd->env->surface, XDIM - 1 - x, y, rbw(x))
				: ft_setpixel(thrd->env->surface, XDIM - 1 - x, y, YELLOW);
		}
		else if (y >= p1 && y < p2)
			ft_setpixel(thrd->env->surface, XDIM - 1 - x, y,
					put_tex(thrd, y, p1, p2));
		if (y >= p2)
		{
			(thrd->env->tex.which_tex == 2)
				? ft_setpixel(thrd->env->surface, XDIM - 1 - x, y, rbw(x))
				: ft_setpixel(thrd->env->surface, XDIM - 1 - x, y, 0x2F4F4FFF);
		}
	}
}

int				ft_is_in_wall(t_env *env, t_point pos)
{
	if (pos.x < 0 || pos.x > env->mapsize.y * env->bloc_size ||
			pos.y < 0 || pos.y > env->mapsize.x * env->bloc_size)
		return (1);
	if (env->map[(int)pos.x / env->bloc_size][(int)pos.y / env->bloc_size] == 1)
		return (1);
	return (0);
}

double			ft_raydata(t_thrd *thrd, t_point step
									, double direction, t_point origin)
{
	double	alpha;

	while (thrd->ray.pos.x > 0 && thrd->ray.pos.x
			< thrd->env->mapsize.y * thrd->env->bloc_size && thrd->ray.pos.y > 0
			&& thrd->ray.pos.y < thrd->env->mapsize.x * thrd->env->bloc_size)
	{
		thrd->ray.pos.x += step.x;
		if (ft_is_in_wall(thrd->env, thrd->ray.pos))
		{
			thrd->ray.side = 1;
			alpha = fabs((thrd->env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(thrd->ray.pos.x - origin.x,
						thrd->ray.pos.y - origin.y) * cos(alpha));
		}
		thrd->ray.pos.y += step.y;
		if (ft_is_in_wall(thrd->env, thrd->ray.pos))
		{
			thrd->ray.side = 2;
			alpha = fabs((thrd->env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(thrd->ray.pos.x - origin.x,
						thrd->ray.pos.y - origin.y) * cos(alpha));
		}
	}
	return (0);
}

double			ft_cast_ray(t_thrd *thrd, double direction)
{
	t_point	step;
	t_point origin;

	step.x = -cos(direction * M_PI / 180) * 0.05;
	step.y = -sin(direction * M_PI / 180) * 0.05;
	thrd->ray.pos.x = thrd->env->player.pos.x * thrd->env->bloc_size;
	thrd->ray.pos.y = thrd->env->player.pos.y * thrd->env->bloc_size;
	origin = (t_point){thrd->ray.pos.x, thrd->ray.pos.y};
	return (ft_raydata(thrd, step, direction, origin));
}

void			*ft_raycasting(void *arg)
{
	t_thrd	*thrd;
	double	wall_height;
	int		i;

	thrd = (t_thrd *)arg;
	thrd->ray.cardinal = 1;
	i = thrd->start;
	while (i < XDIM)
	{
		thrd->ray.direction = (thrd->env->player.dir_d - FOV / 2)
			+ i * ((double)FOV / (double)XDIM);
		thrd->ray.distance = ft_cast_ray(thrd, thrd->ray.direction);
		wall_height = (thrd->env->bloc_size) / thrd->ray.distance * 630;
		ft_put_column(thrd, wall_height, i);
		i += 8;
	}
	pthread_exit(NULL);
}
