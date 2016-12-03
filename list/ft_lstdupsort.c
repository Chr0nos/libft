/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:28:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/12/03 19:02:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdupsort(t_list *lst, int (*cmp)(t_list *, t_list *))
{
	t_list		*sorted;
	t_list		*cpy;

	sorted = NULL;
	while (lst)
	{
		if (!(cpy = ft_memdup(lst, sizeof(t_list))))
		{
			ft_lstdel(&lst, NULL);
			return (NULL);
		}
		cpy->next = NULL;
		ft_lstpush_sort(&sorted, cpy, cmp);
		lst = lst->next;
	}
	return (sorted);
}
