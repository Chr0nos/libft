/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:55:02 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/19 20:23:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_sort(t_list **lst, t_list *item,
	int (*cmp)(t_list *, t_list *))
{
	t_list	*x;
	t_list	*last;

	if (!*lst)
		*lst = item;
	else
	{
		x = *lst;
		last = 0;
		while ((x) && ((*cmp)(x, item) < 0))
		{
			last = x;
			x = x->next;
		}
		if (!last)
			ft_lstadd(lst, item);
		else
			ft_lstinsert(&last, item);
	}
}
