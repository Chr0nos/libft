/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 19:43:36 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/17 20:15:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*ft_list_sort(t_list *lst, int (*cmp)())
{
	t_list	*x;

	x = lst;
	while (x->next)
	{
		if ((*cmp)(x->data, x->next->data) > 0)
		{
			lst = ft_list_swap(x, x->next, lst);
			x = lst;
		}
		else
			x = x->next;
	}
	return (lst);
}
