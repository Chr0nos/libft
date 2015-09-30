/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 18:04:05 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/30 01:58:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_list_swap(t_list *a, t_list *b, t_list **root)
{
	t_list	*parent;
	t_list	*c;

	c = b->next;
	parent = ft_list_parent(a, *root);
	if (parent)
		parent->next = b;
	else
		*root = b;
	a->next = c;
	b->next = a;
}
