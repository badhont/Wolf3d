/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:42:31 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/10 17:42:59 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_clamp(int value, int low, int high)
{
	if (value > high)
		return (high);
	else if (value < low)
		return (low);
	else
		return (value);
}
