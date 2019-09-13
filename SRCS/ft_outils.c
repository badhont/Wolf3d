/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:36:41 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/27 18:10:57 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_load_weapontex(t_env *env)
{
	ft_destroy_items(env);
	if (!(env->tex.widow_0 = IMG_Load("RESSOURCES/pics/weapon/widow.png")))
		ft_error_exit("Wolf3d: Unable to load texture", env);
	if (!(env->tex.widow_1 = IMG_Load("RESSOURCES/pics/weapon/widow2.png")))
		ft_error_exit("Wolf3d: Unable to load texture", env);
	if (!(env->tex.lil_bag = IMG_Load(
		"RESSOURCES/pics/inventory/little_bag.png")))
		ft_error_exit("Wolf3d: Unable to load texture", env);
	if (!(env->tex.bag = IMG_Load("RESSOURCES/pics/inventory/bag.png")))
		ft_error_exit("Wolf3d: Unable to load texture", env);
}

SDL_Color		ft_hex_to_rgb(int hexa)
{
	SDL_Color color;

	color.r = hexa >> 24;
	color.g = hexa >> 16;
	color.b = hexa >> 8;
	color.a = hexa;
	return (color);
}

double			ft_abs(double a)
{
	return (a < 0 ? -a : a);
}

Uint32			ft_getpixel(SDL_Surface *surface, int x, int y, t_env *env)
{
	int				bpp;
	Uint8			*p;
	Uint32			ret;

	if ((SDL_LockSurface(surface)) != 0)
		ft_error_exit("Wolf3d: error getPixel", env);
	x = ft_abs(--x);
	y = ft_abs(--y);
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		ret = *p;
	else if (bpp == 2)
		ret = *(Uint16 *)p;
	else if (bpp == 3)
	{
		ret = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ?
			(p[0] << 16 | p[1] << 8 | p[2]) : (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (bpp == 4)
		ret = *(Uint32 *)p;
	else
		ret = 0;
	SDL_UnlockSurface(surface);
	return (ret | 0xFF000000);
}

void			ft_setpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int			bpp;
	Uint8		*p;

	if (x < 0 || x > XDIM || y < 0 || y > YDIM)
		return ;
	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	(bpp == 1) ? *p = pixel : 0;
	(bpp == 2) ? *(Uint16 *)p = pixel : 0;
	(bpp == 4) ? *(Uint32 *)p = pixel : 0;
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
	}
}
