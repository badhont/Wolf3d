/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:20:44 by badhont           #+#    #+#             */
/*   Updated: 2018/10/10 18:37:27 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_subjoinfree(char **line, char *buff, int len)
{
	char	*tmp;
	char	*tmp2;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	tmp = *line;
	tmp2 = ft_strsub(buff, 0, len);
	if (!(*line = ft_strjoin(tmp, tmp2)))
		return (-1);
	free(tmp);
	free(tmp2);
	return (len);
}

int		get_next_line(int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1] = {'\0'};
	int			ret;
	int			len;

	if (!line || fd < 0 || !(*line = ft_strnew(0)))
		return (-1);
	ret = 1;
	while (ret)
	{
		if (!(*buff) && (ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if ((len = ft_subjoinfree(line, buff, len)) == -1)
			return (-1);
		if (buff[len] == '\n')
		{
			ft_strncpy(buff, buff + len + 1, BUFF_SIZE);
			return (1);
		}
		ft_strncpy(buff, buff + len, BUFF_SIZE);
		if (!(*buff) && ret == 0 && **line)
			return (1);
	}
	return (0);
}
