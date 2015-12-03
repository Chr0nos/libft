/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_foreach_prefix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:19:44 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:20:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
