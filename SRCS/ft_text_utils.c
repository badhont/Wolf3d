/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:30:45 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/28 14:12:02 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface		*ft_selectex(t_thrd *thrd)
{
	if (thrd->ray.side == 2)
	{
		if ((thrd->ray.direction >= 0 && thrd->ray.direction <= 180)
				|| thrd->ray.direction >= 360)
			return (thrd->env->tex.north);
		else
			return (thrd->env->tex.east);
	}
	if (thrd->ray.direction >= 90 && thrd->ray.direction <= 270)
		return (thrd->env->tex.south);
	return (thrd->env->tex.west);
}

Uint32			put_tex(t_thrd *thrd, int y, int p1, int p2)
{
	SDL_Surface	*surface;
	Uint32		color;
	int			x_tex;
	int			y_tex;
	int			ywall;

	ywall = y - p1;
	surface = ft_selectex(thrd);
	if (thrd->ray.side == 2)
		x_tex = ((int)thrd->ray.pos.x % thrd->env->bloc_size)
		* surface->w / thrd->env->bloc_size;
	else
		x_tex = ((int)thrd->ray.pos.y % thrd->env->bloc_size)
		* surface->w / thrd->env->bloc_size;
	y_tex = ywall * surface->h / (p2 - p1);
	color = ft_getpixel(surface, x_tex, y_tex, thrd->env);
	return (color);
}

void			ft_mushroom(t_env *env)
{
	if (env->tex.which_tex == 2)
	{
		if (!(env->tex.north = IMG_Load("RESSOURCES/olol.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.east = IMG_Load("RESSOURCES/olol.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.west = IMG_Load("RESSOURCES/olol.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.south = IMG_Load("RESSOURCES/olol.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
	}
}

void			ft_load_basic(t_env *env)
{
	if (env->tex.which_tex == 0)
	{
		if (!(env->tex.north = IMG_Load("RESSOURCES/pics/basic/wood.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.east = IMG_Load("RESSOURCES/pics/basic/bluestone.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.west = IMG_Load("RESSOURCES/pics/basic/colorstone.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.south = IMG_Load("RESSOURCES/pics/basic/greystone.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
	}
}

void			ft_loadtexture(t_env *env)
{
	ft_load_basic(env);
	if (env->tex.which_tex == 1)
	{
		if (!(env->tex.north = IMG_Load(
			"RESSOURCES/pics/halloffame/sgalasso.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.east = IMG_Load(
			"RESSOURCES/pics/halloffame/asamir-k.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.west = IMG_Load(
			"RESSOURCES/pics/halloffame/badhont.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
		if (!(env->tex.south = IMG_Load(
			"RESSOURCES/pics/halloffame/nihuynh.png")))
			ft_error_exit("Wolf3d: Unable to load texture", env);
	}
	ft_mushroom(env);
}
