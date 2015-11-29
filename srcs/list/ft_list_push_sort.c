/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:55:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:55:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_sort(t_list **lst, void *data, int (*cmp)())
{
	t_list	*x;
	t_list	*last;

	if (!*lst)
		*lst = ft_list_create_elem(data);
	else
	{
		x = *lst;
		last = 0;
		while ((x) && ((*cmp)(x->data, data) < 0))
		{
			last = x;
			x = x->next;
		}
		if (!last)
			ft_list_push_front(lst, data);
		else
			ft_list_insert(&last, data);
	}
}

