/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 00:02:52 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/07 12:35:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_insert(t_list *parent, t_list *item)
{
	t_list	*tmp;

	if (!parent)
		return ;
	tmp = parent->next;
	parent->next = item;
	item->next = tmp;
}

int		ft_list_insert_at(t_list *lst, void *val, unsigned int pos)
{
	unsigned int	p;

	p = 0;
	pos--;
	while (lst)
	{
		if (p == pos)
		{
			ft_list_insert(lst, ft_list_create_elem(val));
			return (1);
		}
		p++;
		lst = lst->next;
	}
	return (0);
}
