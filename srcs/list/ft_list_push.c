/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 19:56:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/03 22:55:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_push_back(t_list **lst, void *data)
{
	t_list	*x;
	t_list	*last;

	if (!lst)
		return ;
	x = ft_list_create_elem(data);
	if (!x)
		return ;
	if (!*lst)
	{
		*lst = x;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = x;
}

void	ft_list_push_front(t_list **lst, void *data)
{
	t_list	*x;

	if (!lst)
		return ;
	x = ft_list_create_elem(data);
	if (!x)
		return ;
	x->next = *lst;
	*lst = x;
}

void	ft_list_push_sort(t_list **lst, void *data, int (*cmp)())
{
	t_list	*x;

	if (!*lst)
		*lst = ft_list_create_elem(data);
	else
	{
		x = *lst;
		while ((x) && ((*cmp)(x->data, data) < 0))
			x = x->next;
		if (x == *lst)
			ft_list_push_front(lst, data);
		else if (!x)
			ft_list_push_back(lst, data);
		else
			ft_list_insert(&x, data);
	}
}

void	ft_list_push_sort_r(t_list **lst, void *data, int (*cmp)())
{
	if (!*lst || ((*lst)->next && (*cmp)((*lst)->data, data) >= 0))
		ft_list_insert(lst, data);
	else if (!(*lst)->next)
		ft_list_insert_before(lst, data);
	else
		ft_list_push_sort(&((*lst)->next), data, cmp);
}