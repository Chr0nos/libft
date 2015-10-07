/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 19:00:18 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/03 11:51:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	ft_btree_foreach_infix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	if (root->left)
		ft_btree_foreach_infix(root->left, f);
	f(root->data);
	if (root->right)
		ft_btree_foreach_infix(root->right, f);
}

void	ft_btree_foreach_prefix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	f(root->data);
	if (root->left)
		ft_btree_foreach_prefix(root->left, f);
	if (root->right)
		ft_btree_foreach_prefix(root->right, f);
}

void	ft_btree_foreach_suffix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	if (root->left)
		ft_btree_foreach_suffix(root->left, f);
	if (root->right)
		ft_btree_foreach_suffix(root->right, f);
	f(root->data);
}
