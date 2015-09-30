/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 23:55:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/30 13:24:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*ft_list_remove(t_list *lst, t_list *item)
{
	t_list	*parent;
	t_list	*next;

	next = item->next;
	if (lst != item)
	{
		parent = ft_list_parent(lst, item);
		if (parent)
			parent->next = next;
	}
	free(item);
	return (next);
}
