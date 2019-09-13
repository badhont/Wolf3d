/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 09:55:41 by asamir-k          #+#    #+#             */
/*   Updated: 2019/04/10 20:08:14 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error_exit("Wolf3d: Unable to initialize SDL2", env);
	if (TTF_Init() < 0)
		ft_error_exit("Wolf3d: Unable to initialize SDL TTF", env);
	if (SDL_Init(SDL_INIT_AUDIO) < 0) 
		ft_error_exit("Wolf3d: Unable to initialize SDL AUDIO", env);
	if (!(env->font = TTF_OpenFont("RESSOURCES/BEBAS.ttf", 100)))
		ft_error_exit("Wolf3d: Unable to get font", env);
	if (Mix_Init(MIX_INIT_MP3) < 0)
		ft_error_exit("Wolf3d: Unable to initialize SDL MP3 MIXER", env);
	if (!(env->sdl.window = SDL_CreateWindow("Wolf3d",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, XDIM, YDIM, 0)))
		ft_error_exit("Wolf3d: Unable to make window", env);
	SDL_RaiseWindow(env->sdl.window);
	if (!(env->sdl.renderer = SDL_CreateRenderer(env->sdl.window, -1,
		SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE)))
		ft_error_exit("Wolf3d: Unable to make renderer", env);
	if (SDL_SetRelativeMouseMode(TRUE) < 0)
		ft_error_exit("Wolf3d: Unable to set relative mode", env);
}

void	init_game(t_env *env)
{
	env->surface = ft_new_surface(YDIM, XDIM, env);
	ft_load_weapontex(env);
	ft_loadtexture(env);
	weapon_sound(env);
	env->player.pos.x = -1;
	env->player.dir_d = 0;
	env->coef_minimap = 1;
	env->bloc_size = 40;
	env->tex.which_tex = 0;
	env->player.life = 100;
	env->player.ammo = 100;
	env->inv_state = 0;
	env->weapon_state = OFF;
	env->weapon = env->tex.widow_0;
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		ft_bzero(&env, sizeof(t_env));
		ft_parsing(&env, av[1]);
		init_game(&env);
		init_sdl(&env);
		ft_wolf_loop(&env);
	}
	ft_putendl("\nHi ^-^ !!! One argument only authorised to make it work.");
	ft_putendl("Have a good time using me, byebye !");
	ft_putendl("\n\n           *pff humans are so retarded wtf ...*");
	return (0);
}
