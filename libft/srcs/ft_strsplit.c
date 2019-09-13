/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:55:37 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/17 12:16:29 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchar(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && !(str[i] == c))
	{
		i++;
	}
	return (i);
}

static int	ft_ct(char *str, char c)
{
	int i;
	int words;
	int nombredemot;

	i = 0;
	nombredemot = 0;
	while (str[i] != '\0')
	{
		words = 0;
		while ((str[i] == c) && str[i])
			i++;
		while ((str[i] != c) && str[i])
		{
			i++;
			words = 1;
		}
		if (words == 1)
			nombredemot++;
	}
	return (nombredemot);
}

char		**ft_strsplit(const char *str, char c)
{
	char	**bak;
	int		tab[4];

	if (!str)
		return (NULL);
	tab[2] = ft_ct((char *)str, c);
	tab[1] = 0;
	if (!(bak = (char**)malloc(sizeof(char *) * (ft_ct((char *)str, c)) + 1)))
		return (NULL);
	while (tab[1] < tab[2])
	{
		while ((*str == c) && *str)
			str++;
		tab[3] = ft_countchar((char*)str, c);
		if (!(bak[tab[1]] = (char*)malloc(sizeof(char) * (tab[3]) + 1)))
			return (NULL);
		bak[tab[1]][tab[3]] = '\0';
		tab[0] = 0;
		while (tab[0] < tab[3])
			bak[tab[1]][tab[0]++] = *str++;
		tab[1]++;
	}
	bak[tab[1]] = 0;
	return (bak);
}
