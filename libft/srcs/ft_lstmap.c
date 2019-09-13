/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 04:02:15 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/14 04:08:46 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*fct;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	fct = f(lst);
	if (!(new = ft_lstnew(fct->content, fct->content_size)))
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst && f)
	{
		fct = f(lst);
		if (!(tmp->next = ft_lstnew(fct->content, fct->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
