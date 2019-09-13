/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inventory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 01:39:25 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/28 13:27:27 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_in_rect(t_env *env)
{
	int posx;
	int	posy;

	SDL_GetMouseState(&(env->realm_x), &(env->realm_y));
	posx = env->realm_x;
	posy = env->realm_y;
	if (posx > env->rekt.x1 && posx < env->rekt.x2
		&& posy > env->rekt.y1 && posy < env->rekt.y2)
		return (1);
	return (0);
}

int			ft_ipod_weapon(t_env *env, int change)
{
	env->rekt = (t_rekt){275, 425, 350, 450};
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
			&& ft_in_rect(env) == 1)
	{
		if (Mix_PlayingMusic() == 0)
			if (Mix_PlayMusic(env->plage, -1) == -1)
				ft_error_exit("Cannot play music", env);
		if (Mix_PausedMusic() == 1)
			Mix_ResumeMusic();
		else
			Mix_PauseMusic();
		change = 1;
	}
	env->rekt = (t_rekt){450, 600, 350, 450};
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
			&& ft_in_rect(env) == 1)
	{
		if (env->weapon_state == 0 || env->weapon_state == 1)
			env->weapon_state = OFF;
		else
			env->weapon_state = 0;
		change = 1;
		ft_reframe(env);
	}
	return (change);
}

int			ft_click_inventory(t_env *env, int change)
{
	if (env->inv_state == 1)
	{
		env->rekt = (t_rekt){275, 425, 460, 550};
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
				&& ft_in_rect(env) == 1)
		{
			env->tex.which_tex = (env->tex.which_tex) ? 0 : 1;
			ft_destroy_texture(env);
			ft_loadtexture(env);
			change = 1;
		}
		env->rekt = (t_rekt){275, 425, 245, 340};
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
				&& ft_in_rect(env) == 1)
		{
			env->tex.which_tex = (env->tex.which_tex) ? 0 : 2;
			ft_destroy_texture(env);
			ft_loadtexture(env);
			change = 1;
		}
		(ft_ipod_weapon(env, change) ? change = 1 : 0);
	}
	return (change);
}

int			ft_inventory_event(t_env *env)
{
	int		change;

	change = 0;
	if (env->sdl.event.type == SDL_KEYDOWN)
	{
		if (env->sdl.event.key.keysym.scancode == SDL_SCANCODE_I)
		{
			env->inv_state = (env->inv_state) ? 0 : 1;
			change = 1;
		}
	}
	return (change);
}

int			ft_inventory(t_env *env)
{
	int			change;
	SDL_Rect	rect;
	SDL_Surface	*inventory;

	change = 0;
	inventory = (env->inv_state == 1) ? env->tex.bag : env->tex.lil_bag;
	if (env->inv_state == 0)
	{
		if (SDL_SetRelativeMouseMode(TRUE) < 0)
			ft_error_exit("Wolf3d: Unable to set relative mode", env);
		rect = (SDL_Rect){0, 630, 150, 150};
		SDL_BlitScaled(inventory, 0, env->surface, &rect);
		rect = (SDL_Rect){50, 650, 15, 20};
		ft_set_string(rect, "Inventory", ft_hex_to_rgb(GREEN), env);
	}
	else
	{
		if (SDL_SetRelativeMouseMode(FALSE) < 0)
			ft_error_exit("Wolf3d: Unable to set relative mode", env);
		rect = (SDL_Rect){0, 200, 700, 400};
		SDL_BlitScaled(inventory, 0, env->surface, &rect);
	}
	return (change);
}
