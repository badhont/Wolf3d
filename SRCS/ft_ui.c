/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:42:09 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/28 14:13:37 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_set_string(SDL_Rect rect, char *text,
		SDL_Color color, t_env *env)
{
	SDL_Rect			sdl_rect;
	SDL_Surface			*surface;

	sdl_rect = (SDL_Rect){rect.x, rect.y, rect.w, rect.h};
	if (!(surface = TTF_RenderText_Blended(env->font, text, color)))
		ft_error_exit("Wolf3d: Error while making surface", env);
	sdl_rect.w = (sdl_rect.h * surface->w) / surface->h;
	if ((SDL_BlitScaled(surface, 0, env->surface, &sdl_rect)) == -1)
		ft_error_exit("Wolf3d: Error can't blit surface", env);
	SDL_FreeSurface(surface);
}

SDL_Color		ft_color_nb_state(int nb)
{
	if (nb > 0 && nb < 25)
		return (ft_hex_to_rgb(0xFF0000FF));
	if (nb >= 25 && nb < 50)
		return (ft_hex_to_rgb(0xFFA500FF));
	if (nb >= 50 && nb < 75)
		return (ft_hex_to_rgb(0xFFFF00FF));
	if (nb >= 75 && nb <= 100)
		return (ft_hex_to_rgb(0x32CD32FF));
	return (ft_hex_to_rgb(WHITE));
}

void			ft_value_display(t_env *env)
{
	SDL_Rect		rect;

	rect = (SDL_Rect){0, 0, 60, 30};
	ft_set_string(rect, "HP", ft_color_nb_state(env->player.life), env);
	rect = (SDL_Rect){0, 40, 60, 30};
	ft_set_nbrstring(env->player.life, rect,
			ft_color_nb_state(env->player.life), env);
	rect = (SDL_Rect){0, 80, 60, 30};
	ft_set_string(rect, "AMMO", ft_hex_to_rgb(rbw(PURPLE)), env);
	rect = (SDL_Rect){0, 120, 60, 30};
	ft_set_nbrstring(env->player.ammo, rect,
			ft_color_nb_state(env->player.ammo), env);
	rect = (SDL_Rect){100, 100, 0, 30};
}

void			weapon_sound(t_env *env)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
		ft_error_exit("Can't open audio", env);
	if (!(env->plage = Mix_LoadMUS("RESSOURCES/sound/plage.wav")))
		ft_error_exit("Wolf3d: Unable to load music", env);
	if (!(env->widow_rifle = Mix_LoadWAV("RESSOURCES/sound/pew.wav")))
		ft_error_exit("Wolf3d: Unable to load sound effect", env);
}

void			ft_ui(t_env *env)
{
	SDL_Rect	rect;

	ft_value_display(env);
	if (env->weapon_state == 1)
		env->weapon = (env->weapon == env->tex.widow_1)
			? env->tex.widow_0 : env->tex.widow_1;
	rect = (SDL_Rect){XDIM / 3.5, 0, XDIM, YDIM};
	if (env->weapon_state != 2)
		SDL_BlitScaled(env->weapon, 0, env->surface, &rect);
	ft_inventory(env);
}
