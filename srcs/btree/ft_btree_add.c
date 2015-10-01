/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 15:53:00 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/01 23:25:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	ft_btree_add(t_btree **root, void *data, int (*f)())
{
	t_btree	*x;

	if ((!root) || (!*root))
		*root = ft_btree_create_node(data);
	else if (f((*root)->data, data) <= 0)
	{
		if ((*root)->left)
		{
			if (f((*root)->left->data, data) > 0)
			{
				x = (*root)->left;
				(*root)->left = ft_btree_create_node(data);
				(*root)->left->left = x;
			}
			else
				ft_btree_add(&(*root)->left, data, f);
		}
		else
			(*root)->left = ft_btree_create_node(data);
	}
	else if ((*root)->right)
		ft_btree_add(&(*root)->right, data, f);
	else
		(*root)->right = ft_btree_create_node(data);
}
