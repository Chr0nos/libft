/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 12:46:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/02 19:47:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree		*ft_btree_search_mess(t_btree *root, void *val, int (*f)())
{
	if (!root)
		return (0);
	if (f(root->data, val) == 0)
		return (root);
	if (root->left)
		return (ft_btree_search_mess(root->left, val, f));
	if (root->right)
		return (ft_btree_search_mess(root->right, val, f));
	return (0);
}

t_btree		*ft_btree_search(t_btree *root, void *val, int (*f)())
{
	int		r;

	if (!root)
		return (0);
	r = f(root->data, val);
	if (r == 0)
		return (root);
	else if (r < 0)
		return (ft_btree_search(root->left, val, f));
	else
		return (ft_btree_search(root->right, val, f));
}
