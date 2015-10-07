/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 15:33:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/03 11:24:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	ft_btree_insert(t_btree **node, void *data, int (*f)())
{
	t_btree		*x;

	x = *node;
	*node = ft_btree_create_node(data);
	if (f((*node)->data, data) < 0)
		(*node)->left = x;
	else
		(*node)->right = x;
}
