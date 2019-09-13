 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:14:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/28 14:07:03 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_check_first_line(char *line, t_env *env)
{
	int		i;

	i = 0;
	if (!(env->mapsize.x = ft_atoi(line)))
		ft_error_exit("Wolf3d: Map: First line: Must begin by a number", env);
	i += ft_numberlen(env->mapsize.x);
	if (line[i] != ' ')
		ft_error_exit("Wolf3d: Map: First line: One space required", env);
	i++;
	env->mapsize.y = ft_atoi(line + i);
	i += ft_numberlen(env->mapsize.y);
	if (line[i])
		ft_error_exit("Wolf3d: Map: First line: Two numbers required", env);
	if (env->mapsize.x > MAX_DIM || env->mapsize.y > MAX_DIM)
		ft_error_exit("Wolf3d: The map is larger than 200", env);
	return (1);
}

void		ft_check_map_line(char *line, t_env *env)
{
	int		i;

	i = 0;
	if (!(ft_isdigit(line[0])))
		ft_error_exit("Wolf3d: Map: First char isn't a digit", env);
	while (line[i])
	{
		if (!((ft_isdigit(line[i]) && (line[i + 1] == ' ' || line[i + 1] == 0))
			|| (line[i] == ' ' && ft_isdigit(line[i + 1]))))
			ft_error_exit("Wolf3d: Map: Bad map format", env);
		i++;
	}
	i = (i == 1) ? 1 : (i + 1) / 2;
	if (i != env->mapsize.x)
		ft_error_exit("Wolf3d: Map: i != mapsize.x", env);
}

int			ft_stock_line(char *line, int y, t_env *env)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!(env->map[y] = (int *)ft_memalloc(sizeof(int) * (env->mapsize.x))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);
	while (line[i])
	{
		env->map[y][x] = ft_atoi(line + i);
		if (env->map[y][x] == 2)
		{
			if (env->player.pos.x > 0)
				ft_error_exit("Wolf3d: there could be only one spawn", env);
			env->player.pos.x = y;
			env->player.pos.y = x;
		}
		i = (line[i + 1]) ? i + 2 : i + 1;
		x++;
	}
	return (1);
}

int			ft_check_characters(char *str, t_env *env)
{
	int			fd;
	int			i;
	int			newline;
	static char buff[MAX_DIM + 1] = {'\0'};

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open the file", env);
	if (read(fd, buff, MAX_DIM) == -1)
		ft_error_exit("Wolf3d: Unable to read the map", env);
	close(fd);
	i = 0;
	newline = 0;
	while (buff[i])
	{
		if (!(ft_isdigit(buff[i])) && buff[i] != ' ' && buff[i] != '\n')
			ft_error_exit("Wolf3d: Invalid character", env);
		if (buff[i] == '\n')
			newline++;
		i++;
	}
	if (newline == 0)
		ft_error_exit("Wolf3d: Newline character not found", env);
	return (1);
}

void		ft_parsing(t_env *env, char *str)
{
	int			fd;
	int			nb_line;
	char		*line;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open the file", env);
	ft_check_characters(str, env);
	if (get_next_line(fd, &line) == 1 && ft_check_first_line(line, env))
		ft_strdel(&line);
	if (!(env->map = (int **)ft_memalloc(sizeof(int *) * (env->mapsize.y))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);
	nb_line = 0;
	while (get_next_line(fd, &line) == 1)
	{
		ft_check_map_line(line, env);
		ft_stock_line(line, nb_line, env);
		ft_strdel(&line);
		nb_line++;
	}
	ft_strdel(&line);
	if (nb_line != env->mapsize.y)
		ft_error_exit("Wolf3d: Invalid map format", env);
	if (env->player.pos.x == -1)
		ft_error_exit("Wolf3d: Map: One spawn point required", env);
	close(fd);
}
