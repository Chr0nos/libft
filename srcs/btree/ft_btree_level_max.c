/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:54:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/29 13:06:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_size	ft_btree_level_max_r(t_btree *root, t_size lvl, t_size max)
{
	if (!root)
		return (0);
	lvl++;
	if (lvl > max)
		max = lvl;
	if (root->left)
		return (ft_btree_level_max_r(root->left, lvl, max));
	else if (root->right)
		return (ft_btree_level_max_r(root->right, lvl, max));
	else
		return (max);
}

t_size	ft_btree_level_max(t_btree *root)
{
	return (ft_btree_level_max_r(root, 0, 0));
}
