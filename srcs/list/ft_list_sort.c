/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 19:43:36 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/30 02:05:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_sort(t_list **lst, int (*cmp)())
{
	t_list	*x;

	if ((!lst) || (!*lst))
		return ;
	x = *lst;
	while (x->next)
	{
		if ((*cmp)(x->data, x->next->data) > 0)
		{
			ft_list_swap(x, x->next, lst);
			x = *lst;
		}
		else
			x = x->next;
	}
}
