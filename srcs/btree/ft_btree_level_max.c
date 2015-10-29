/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:54:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/29 13:22:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	ft_btree_level_max_r(t_btree *root, t_size lvl, t_size *m)
{
	if (!root)
		return ;
	lvl++;
	if (lvl > *m)
		*m = lvl;
	if (root->left)
		ft_btree_level_max_r(root->left, lvl, m);
	else if (root->right)
		ft_btree_level_max_r(root->right, lvl, m);
}

t_size	ft_btree_level_max(t_btree *root)
{
	t_size	max;

	max = 0;
	ft_btree_level_max_r(root, 0, &max);
	return (max);
}
