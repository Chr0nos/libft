/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 12:46:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/02 12:56:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree		*ft_btree_search(t_btree *root, void *val, int (*f)())
{
	if (!root)
		return (0);
	if (f(root->data, val) == 0)
		return (root);
	if (root->left)
		ft_btree_search(root->left, val, f);
	if (root->right)
		ft_btree_search(root->right, val, f);
	return (0);
}
