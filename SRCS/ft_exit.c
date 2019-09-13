/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:42:55 by badhont           #+#    #+#             */
/*   Updated: 2019/03/28 13:48:45 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_destroy_texture(t_env *env)
{
	if (env->tex.north)
		SDL_FreeSurface(env->tex.north);
	if (env->tex.west)
		SDL_FreeSurface(env->tex.west);
	if (env->tex.south)
		SDL_FreeSurface(env->tex.south);
	if (env->tex.east)
		SDL_FreeSurface(env->tex.east);
}

void	ft_destroy_items(t_env *env)
{
	if (env->tex.widow_0)
		SDL_FreeSurface(env->tex.widow_0);
	if (env->tex.widow_1)
		SDL_FreeSurface(env->tex.widow_1);
	if (env->tex.lil_bag)
		SDL_FreeSurface(env->tex.lil_bag);
	if (env->tex.bag)
		SDL_FreeSurface(env->tex.bag);
}

void	ft_error_exit(char *str, t_env *env)
{
	if (env->surface)
		SDL_FreeSurface(env->surface);
	ft_destroy_texture(env);
	ft_destroy_items(env);
	if (env->font)
		TTF_CloseFont(env->font);
	if (env->sdl.renderer)
		SDL_DestroyRenderer(env->sdl.renderer);
	if (env->sdl.window)
		SDL_DestroyWindow(env->sdl.window);
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_env *env)
{
	if (env->surface)
		SDL_FreeSurface(env->surface);
	ft_destroy_texture(env);
	ft_destroy_items(env);
	if (env->font)
		TTF_CloseFont(env->font);
	if (env->sdl.renderer)
		SDL_DestroyRenderer(env->sdl.renderer);
	if (env->sdl.window)
		SDL_DestroyWindow(env->sdl.window);
	Mix_FreeChunk(env->widow_rifle);
	Mix_FreeMusic(env->plage);
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
	exit(EXIT_SUCCESS);
}
