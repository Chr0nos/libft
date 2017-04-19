/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 15:33:55 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/19 20:26:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert(t_btree **node, void *data, int (*f)(void *, void *))
{
	t_btree		*x;

	x = *node;
	*node = ft_btree_create_node(data);
	if (f((*node)->data, data) < 0)
		(*node)->left = x;
	else
		(*node)->right = x;
}
