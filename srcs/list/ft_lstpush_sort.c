/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:55:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 18:10:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_sort(t_list **lst, void *data, size_t size, int (*cmp)())
{
	t_list	*x;
	t_list	*last;

	if (!*lst)
		*lst = ft_lstnew(data, size);
	else
	{
		x = *lst;
		last = 0;
		while ((x) && ((*cmp)(x->content, data) < 0))
		{
			last = x;
			x = x->next;
		}
		if (!last)
			ft_lstadd(lst, ft_lstnew(data, size));
		else
			ft_lstinsert(&last, ft_lstnew(data, size));
	}
}
