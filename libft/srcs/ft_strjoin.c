/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:31:56 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/17 12:17:23 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*fresh;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(fresh = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	fresh[0] = '\0';
	fresh = ft_strcat(fresh, s1);
	fresh = ft_strcat(fresh, s2);
	return (fresh);
}
