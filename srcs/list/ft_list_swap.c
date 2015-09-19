/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 18:04:05 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/17 20:13:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*ft_list_swap(t_list *a, t_list *b, t_list *root)
{
	t_list	*parent;

	parent = ft_list_parent(a, root);
	if (parent)
		parent->next = b;
	else
		root = b;
	a->next = b->next;
	b->next = a;
	return (root);
}
