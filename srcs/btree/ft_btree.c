/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 23:34:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/01 16:09:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "btree.h"

t_btree	*ft_btree_create_node(void *data)
{
	t_btree	*root;

	root = malloc(sizeof(t_btree));
	if (!root)
		return (0);
	root->left = 0;
	root->right = 0;
	root->data = data;
	return (root);
}
