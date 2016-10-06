/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 15:33:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:28:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
