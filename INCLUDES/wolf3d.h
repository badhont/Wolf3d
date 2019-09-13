/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:08:24 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/28 17:13:12 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <pthread.h>
# include <math.h>

# define YDIM 2000
# define XDIM 2000
# define TEX_W 64
# define TEX_H 64
# define MAX_DIM 200

# define PINK 0xFFE62BFD
# define BLUE 0xFFFD1200
# define RED 0xFFFD0000
# define CYAN 0xFF00F3FD
# define YELLOW 0xFFFDF800
# define GREEN 0xFF00FD05
# define BROWN 0xFF29468C
# define ORANGE 0xFFF87C00
# define WHITE 0xFFFFFFFF
# define BLACK 0xFF000000
# define PURPLE 0xFF7400AC
# define GREY 0xFF9A9A9A

# define FORWARD 0
# define RIGHT 90
# define BACKWARD 180
# define LEFT 270
# define OFF 2
# define FOV 60
# define MOUSE_SENS 12

# define NB_THRD 8

typedef	struct s_sdl		t_sdl;
typedef struct s_thrd		t_thrd;
typedef	struct s_point		t_point;
typedef	struct s_rect		t_rect;
typedef	struct s_player		t_player;
typedef	struct s_line		t_line;
typedef	struct s_ray		t_ray;
typedef	struct s_tex		t_tex;
typedef	struct s_env		t_env;
typedef struct s_rekt		t_rekt;
typedef	struct s_pos		t_pos;

struct						s_sdl
{
	SDL_Event				event;
	SDL_Window				*window;
	SDL_Renderer			*renderer;
};

struct						s_point
{
	double					x;
	double					y;
};

struct						s_pos
{
	int						x;
	int						y;
};

struct						s_rect
{
	double					x;
	double					y;
	double					width;
	double					height;
};

struct						s_ray
{
	double					direction;
	int						cardinal;
	double					distance;
	int						side;
	t_point					pos;
};

struct						s_thrd
{
	pthread_t				th;
	t_env					*env;
	int						start;
	t_ray					ray;
};

struct						s_player
{
	t_point					pos;
	double					dir_d;
	double					dir_r;
	int						ammo;
	int						life;
};

struct						s_line
{
	int						x;
	int						y;
	int						d;
	int						dx;
	int						dy;
	int						s1;
	int						s2;
};

struct						s_tex
{
	SDL_Surface				*north;
	SDL_Surface				*west;
	SDL_Surface				*south;
	SDL_Surface				*east;
	SDL_Surface				*widow_0;
	SDL_Surface				*widow_1;
	SDL_Surface				*lil_bag;
	SDL_Surface				*bag;
	int						which_tex;
	int						w_tex;
	int						h_tex;
};

struct						s_rekt
{
	int						x1;
	int						x2;
	int						y1;
	int						y2;
};

struct						s_env
{
	int						x_tex;
	int						y_tex;
	t_rekt					rekt;
	int						realm_x;
	int						realm_y;
	int						w_tex;
	int						h_tex;
	Mix_Music				*plage;
	Mix_Chunk				*widow_rifle;
	int						click_state;
	int						weapon_state;
	int						inv_state;
	int						bloc_size;
	t_sdl					sdl;
	t_tex					tex;
	SDL_Surface				*surface;
	TTF_Font				*font;
	int						**map;
	t_player				player;
	int						mouse_x;
	int						mouse_y;
	Uint32					last;
	int						coef_minimap;
	t_point					ray_pos;
	SDL_Surface				*weapon;
	int						nb_frames;
	t_pos					mapsize;
};

/*
**	Init / Parsing
*/

void						ft_parsing(t_env *env, char *str);

/*
**	Wolf3d
*/

void						ft_wolf_loop(t_env *env);
void						*ft_raycasting(void *arg);
void						ft_set_player_dir(t_env *env);
void						ft_minimap(t_env *env);
void						ft_crosshair(t_env *env);

/*
**	Events
*/

int							events(t_env *env);

/*
**	Utils
*/

int							ft_is_in_wall(t_env *env, t_point pos);
void						weapon_sound(t_env *env);
void						sound_control(t_env *env);
void						ft_set_string(SDL_Rect rect, char *text,
								SDL_Color color, t_env *env);
int							ft_click_inventory(t_env *env, int change);
int							ft_inventory_event(t_env *env);
/*
**	Graphics
*/

SDL_Surface					*ft_new_surface(int height, int width, t_env *env);
void						ft_load_weapontex(t_env *env);
void						ft_loadtexture(t_env *env);
Uint32						ft_getpixel(SDL_Surface *surface
								, int x, int y, t_env *env);
void						ft_setpixel(SDL_Surface *surface
								, int x, int y, Uint32 pixel);
void						dl(t_env *env, t_point pt1, t_point pt2, int color);
SDL_Color					ft_hex_to_rgb(int hexa);
void						ft_reframe(t_env *env);
void						ft_ui(t_env *env);
Uint32						put_tex(t_thrd *thrd, int y, int p1, int p2);
SDL_Surface					*ft_selectex(t_thrd *thrd);
int							rbw(int x);
double						ft_pythagore(double posx, double posy);
void						ft_set_nbrstring(int value, SDL_Rect rect,
							SDL_Color color, t_env *env);
/*
**	Exit
*/

void						ft_error_exit(char *str, t_env *env);
void						ft_exit(t_env *env);
void						ft_destroy_texture(t_env *env);
void						ft_destroy_items(t_env *env);
int							ft_inventory(t_env *env);
#endif
