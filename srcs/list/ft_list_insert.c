/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 00:02:52 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/03 22:39:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_insert(t_list **parent, void *data)
{
	t_list	*tmp;
	t_list	*x;

	if (!parent)
		return ;
	if (!*parent)
		*parent = ft_list_create_elem(data);
	else
	{
		x = ft_list_create_elem(data);
		if (x)
		{
			tmp = (*parent)->next;
			(*parent)->next = x;
			x->next = tmp;
		}
	}
}

int		ft_list_insert_at(t_list *lst, void *val, unsigned int pos)
{
	unsigned int	p;

	p = 0;
	while (lst)
	{
		if (p == pos)
		{
			ft_list_insert(&lst, ft_list_create_elem(val));
			return (1);
		}
		p++;
		lst = lst->next;
	}
	return (0);
}

void	ft_list_insert_before(t_list **parent, void *data)
{
	t_list	*x;

	if (!parent)
		return ;
	x = ft_list_create_elem(data);
	if (x)
	{
		x->next = *parent;
		*parent = x;
	}
}
