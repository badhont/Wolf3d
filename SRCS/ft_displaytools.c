/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaytools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:03:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/26 19:23:20 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_set_nbrstring(int value, SDL_Rect rect,
					SDL_Color color, t_env *env)
{
	char	*str;

	if (!(str = ft_itoa(value)))
		ft_error_exit("itoa dhont allowed", env);
	ft_set_string(rect, str, color, env);
	ft_strdel(&str);
}

double			ft_pythagore(double posx, double posy)
{
	return (sqrt(posx * posx + posy * posy));
}

int				rbw(int x)
{
	int			color;
	int			whichcolor;
	int			thiscolor;
	static int	rainbow[7] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE};

	color = 0;
	whichcolor = (XDIM) / 7;
	thiscolor = 0;
	while (color < 6)
	{
		thiscolor = thiscolor + whichcolor;
		if (x <= thiscolor)
			return (rainbow[color]);
		color++;
	}
	return (rainbow[color]);
}

void			ft_crosshair(t_env *env)
{
	t_point pt1;
	t_point pt2;

	pt1.x = XDIM / 2 - 1;
	pt1.y = YDIM / 2 - 7;
	pt2.x = XDIM / 2 - 1;
	pt2.y = YDIM / 2 + 8;
	dl(env, pt1, pt2, PINK);
	pt1.x = XDIM / 2 - 8;
	pt1.y = YDIM / 2;
	pt2.x = XDIM / 2 + 7;
	pt2.y = YDIM / 2;
	dl(env, pt1, pt2, PINK);
}
