/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 13:19:05 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/02 20:53:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list		*ft_list_parent(t_list *item, t_list *root)
{
	if (!root)
		return (0);
	while (root->next)
	{
		if (root->next == item)
			return (root);
		root = root->next;
	}
	return (0);
}

int			ft_list_size(t_list *lst)
{
	int		p;

	p = 0;
	while (lst)
	{
		p++;
		lst = lst->next;
	}
	return (p);
}

t_list		*ft_list_create_elem(void *data)
{
	t_list	*x;

	x = malloc(sizeof(t_list));
	if (x)
	{
		x->data = data;
		x->next = 0;
	}
	return (x);
}

t_list		*ft_list_last(t_list *item)
{
	if (!item)
		return (0);
	while (item->next)
		item = item->next;
	return (item);
}
