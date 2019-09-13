/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:47:53 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/12 16:32:02 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
	{
		i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
	}
	len = ft_strlen(s);
	if (s[len] == '\0')
		len--;
	while (s[len] == '\n' || s[len] == '\t' || s[len] == ' ')
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
