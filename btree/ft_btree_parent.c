/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/03 11:28:56 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:29:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_btree_parent(t_btree *root, t_btree *item)
{
	if (!root)
		return (0);
	if ((root->left == item) || (root->right == item))
		return (root);
	if (root->left)
		return (ft_btree_parent(root->left, item));
	if (root->right)
		return (ft_btree_parent(root->right, item));
	return (0);
}
