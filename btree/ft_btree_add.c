/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 15:53:00 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/19 20:26:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_add(t_btree **root, void *data, int (*f)(void *, void *))
{
	if (!root)
		return ;
	if (!*root)
		*root = ft_btree_create_node(data);
	if (f((*root)->data, data) < 0)
	{
		if ((*root)->left)
			ft_btree_add(&(*root)->left, data, f);
		else
			ft_btree_insert(&(*root)->left, data, f);
	}
	else if ((*root)->right)
		ft_btree_add(&(*root)->right, data, f);
	else
		ft_btree_insert(&(*root)->right, data, f);
}
