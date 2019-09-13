/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:34:46 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/10 20:24:23 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			i;

	nb = n;
	i = ft_lenint(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[--i] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
