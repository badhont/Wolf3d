/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcatt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:23:59 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/07 18:33:20 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lend;
	size_t lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size <= lend)
		return (lens + size);
	else
		ft_strncat(dst, src, size - lend - 1);
	return (lend + lens);
}
