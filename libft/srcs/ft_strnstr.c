/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:55:02 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/07 18:34:45 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[j] != '\0' && j < len)
	{
		i = 0;
		while (needle[i] == haystack[j + i] && (j + i <= len))
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack + j);
		}
		j++;
	}
	return (NULL);
}
