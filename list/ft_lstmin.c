/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:29:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/12/10 17:36:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the lowest value item of a chained list
** to get the max value use a revert cmp function
** in case of 1 element list: the element is the lowest of the list so it will
** be returned
*/

t_list	*ft_lstmin(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	t_list	*min;

	min = lst;
	lst = lst->next;
	while (lst)
	{
		if (cmp(min, lst) > 0)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
