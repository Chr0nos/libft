/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:38:12 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 19:51:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **lst, t_list *a, t_list *b)
{
	t_list	*parent;
	t_list	*c;

	c = b->next;
	if (!(parent = ft_lstparent(*lst, a)))
		*lst = c;
	else
		parent->next = b;
	a->next = c;
	b->next = a;
}
