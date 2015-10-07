/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 19:56:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/07 13:34:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_list_push_back(t_list **lst, void *data)
{
	t_list	*x;
	t_list	*last;

	if (!lst)
		return (0);
	x = ft_list_create_elem(data);
	if (!*lst)
	{
		*lst = x;
		return (*lst);
	}
	last = ft_list_last(*lst);
	if (last)
		last->next = x;
	return (*lst);
}

t_list	*ft_list_push_front(t_list **lst, void *data)
{
	t_list	*x;

	x = ft_list_create_elem(data);
	x->next = *lst;
	*lst = x;
	return (*lst);
}

t_list	*ft_list_push_sort(t_list **lst, void *data, int (*cmp)(void *, void *))
{
	t_list	*x;

	if (!lst)
		return (0);
	if (!*lst)
		*lst = ft_list_create_elem(data);
	else
	{
		x = *lst;
		while ((x->next) && ((*cmp)(x->data, data) < 0))
		{
			if ((*cmp)(x->next->data, data) >= 0)
			{
				ft_list_insert(x, data);
				return (*lst);
			}
			x = x->next;
		}
		x->next = ft_list_create_elem(data);
	}
	return (*lst);
}
