/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:55:29 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/12 17:06:15 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ctword(char *str)
{
	int		i;
	int		countwords;
	int		word;

	i = 0;
	countwords = 0;
	while (str[i])
	{
		word = 0;
		while (str[i] == ' ' && str[i])
			i++;
		while (str[i] && (str[i] != ' '))
		{
			i++;
			word = 1;
		}
		if (word == 1)
			countwords++;
	}
	return (countwords);
}
