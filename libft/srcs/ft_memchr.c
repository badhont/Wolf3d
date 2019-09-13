/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:58:01 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/08 17:33:56 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	letter;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	letter = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == letter)
			return (str + i);
		i++;
	}
	return (NULL);
}
