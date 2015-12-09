/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_foreach_suffix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:20:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:20:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
