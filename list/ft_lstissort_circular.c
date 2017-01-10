/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissort_circular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:15:26 by snicolet          #+#    #+#             */
/*   Updated: 2017/01/10 04:58:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** detects if a list is sorted in a circular mode, ex:
** b c d e f a a : is sorted
*/

int		ft_lstissort_circular(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	t_list	*first;

	if (!lst)
		return (1);
	first = lst;
	while ((lst->next) && (cmp(lst, lst->next) <= 0))
		lst = lst->next;
	lst = lst->next;
	if (!lst)
		return (1);
	while ((lst->next) && ((cmp(lst, lst->next) == 0) || (cmp(lst->next, first) == 0)))
		lst = lst->next;
	if (lst->next)
		return (0);
	if (cmp(first, lst) < 0)
		return (0);
	return (1);
}
