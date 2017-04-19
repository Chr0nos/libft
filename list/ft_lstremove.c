/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:17:33 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/19 20:22:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstremove(t_list **item, t_list **root, void (*f)(void *))
{
	t_list	*parent;
	t_list	*dent;

	if (*item)
	{
		parent = ft_lstparent(*root, *item);
		if (parent)
			parent->next = (*item)->next;
		if (f)
			f((*item)->content);
		if (*item == *root)
		{
			dent = *item;
			*root = (*item)->next;
		}
		else
		{
			dent = *item;
			*item = 0;
		}
		free(dent);
	}
}
