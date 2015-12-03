/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 16:25:11 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:29:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btree_level(t_btree *root, t_btree *item, int level)
{
	if (!root)
		return (-1);
	if (root == item)
		return (level);
	if (root->left)
		return (ft_btree_level(root->left, item, level + 1));
	if (root->right)
		return (ft_btree_level(root->right, item, level + 1));
	return (-2);
}
