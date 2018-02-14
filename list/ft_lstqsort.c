/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstqsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:00:56 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/14 11:36:33 by snicolet         ###   ########.fr       */
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
	void				**tab;

	tab = ft_lsttotab_size(lst, size);
	if (!tab)
		return (NULL);
	ft_quicksort(tab, 0, size, cmp);
	return (tab);
}
