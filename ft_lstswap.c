/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:38:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/08 15:42:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstswap(t_list *root, t_list *a, t_list *b)
{
	t_list	*bnext;
	t_list	*parent;

	parent = ft_lstparent(root, a);
	if (parent)
		parent->next = b;
	else
		root = b;
	bnext = b->next;
	b->next = a;
	a->next = bnext;
	return (root);
}
