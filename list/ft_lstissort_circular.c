/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissort_circular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:15:26 by snicolet          #+#    #+#             */
/*   Updated: 2017/01/12 01:22:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** detects if a list is sorted in a circular mode, ex:
** b c d e f a a : is sorted
*/

int		ft_lstissort_circular(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	t_list		*first;
	t_list		*last;

	if (!lst)
		return (1);
	first = lst;
	while ((lst->next) && (cmp(lst, lst->next) <= 0))
		lst = lst->next;
	lst = lst->next;
	if (!lst)
		return (1);
	last = lst;
	while ((lst) && (lst->next))
	{
		if (cmp(lst, lst->next) > 0)
			return (0);
		last = lst;
		lst = lst->next;
	}
	return ((cmp(last, first) > 0) ? 0 : 1);
}
