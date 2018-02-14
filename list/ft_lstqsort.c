/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstqsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:00:56 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/14 11:03:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** convert a unsorted chained list into a sorted void** array
** using a quicksort algorythm method.
** the returned array will have a NULL at the end.
*/

void		**ft_lstqsort(t_list *lst, int (*cmp)(void *, void *))
{
	const size_t		size = ft_lstsize(lst);
	size_t				p;
	void				**tab;

	tab = malloc(sizeof(void*) * (size + 1));
	if (!tab)
		return (NULL);
	p = 0;
	while ((p < size) && (lst))
	{
		tab[p++] = lst->content;
		lst = lst->next;
	}
	tab[p] = NULL;
	ft_quicksort((void**)tab, 0, size, cmp);
	return (tab);
}
