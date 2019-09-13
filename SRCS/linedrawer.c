/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedrawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:03:54 by asamir-k          #+#    #+#             */
/*   Updated: 2019/04/10 20:08:25 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		signdetector(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}

int		no_overdraw(t_point pt1, t_point pt2)
{
	if ((pt1.x < 0 || pt1.x > XDIM || pt1.y < 0 || pt1.y > YDIM)
		&& (pt2.x < 0 || pt2.x > YDIM || pt2.y < 0 || pt2.y > YDIM))
		if (!(pt1.y < 0 && pt2.y > YDIM))
			if (!(pt2.y < 0 && pt1.y > YDIM))
				if (!(pt1.x < 0 && pt2.x > YDIM))
					if (!(pt2.x < 0 && pt1.x > YDIM))
						return (1);
	return (0);
}

void	ft_brosenham(t_env *env, t_line *line, int color, int swap)
{
	int i;

	i = 1;
	while (i <= line->dx)
	{
		if (line->x < 0 || line->x > XDIM || line->y < 0 || line->y > YDIM)
			break ;
		ft_setpixel(env->surface, line->x, line->y, color);
		while (line->d >= 0)
		{
			line->d = line->d - 2 * line->dx;
			if (swap)
				line->x = line->x + line->s1;
			else
				line->y = line->y + line->s2;
		}
		if (swap)
			line->y = line->y + line->s2;
		else
			line->x = line->x + line->s1;
		line->d = line->d + 2 * line->dy;
		i++;
	}
}

void	dl(t_env *env, t_point pt1, t_point pt2, int color)
{
	t_line	*line;
	int		swap;
	int		temp;

	if (no_overdraw(pt1, pt2) == 1)
		return ;
	swap = 0;
	if (!(line = ft_memalloc(sizeof(t_line))))
		ft_error(__func__, __LINE__);
	line->dx = fabs(pt2.x - pt1.x);
	line->dy = fabs(pt2.y - pt1.y);
	line->s1 = signdetector(pt2.x - pt1.x);
	line->s2 = signdetector(pt2.y - pt1.y);
	if (line->dy > line->dx)
	{
		temp = line->dx;
		line->dx = line->dy;
		line->dy = temp;
		swap = 1;
	}
	line->d = 2 * line->dy - line->dx;
	line->x = pt1.x;
	line->y = pt1.y;
	ft_brosenham(env, line, color, swap);
	free(line);
}
