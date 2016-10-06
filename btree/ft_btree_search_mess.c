/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_mess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:25:36 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:25:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
