/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:51:53 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/06 19:43:02 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
{
	char *tmp;

	if (!(tmp = ft_strsub(s, start, len)))
		return (NULL);
	free(s);
	return (tmp);
}
