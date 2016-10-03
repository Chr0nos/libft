/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:54:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:29:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_btree_level_max_r(t_btree *root, size_t lvl, size_t *m)
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

size_t			ft_btree_level_max(t_btree *root)
{
	size_t	max;

	max = 0;
	ft_btree_level_max_r(root, 0, &max);
	return (max);
}
