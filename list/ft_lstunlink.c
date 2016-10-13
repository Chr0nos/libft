/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstunlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:44:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/13 03:51:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function just unlink item from lst, return 1 if the item was found
** otherwise 0
*/

int		ft_lstunlink(t_list **lst, t_list *item)
{
	t_list	*x;

	x = *lst;
	if (!x)
		return (0);
	if (x == item)
	{
		*lst = (*lst)->next;
		return (1);
	}
	while (x->next)
	{
		if (x->next == item)
		{
			x->next = x->next->next;
			return (1);
		}
		x = x->next;
	}
	return (0);
}
