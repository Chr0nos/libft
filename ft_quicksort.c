/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 16:35:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/16 12:19:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	partition(void **tab, size_t start, size_t end,
	int (*cmp)(void *, void *))
{
	size_t		i;
	size_t		pivot;

	pivot = start;
	i = start;
	while (i <= end)
	{
		if (cmp(tab[i], tab[start]) < 0)
		{
			pivot++;
			ft_swap_ptr(&tab[i], &tab[pivot]);
		}
		i++;
	}
	ft_swap_ptr(&tab[start], &tab[pivot]);
	return (pivot);
}

void			ft_quicksort(void **tab, size_t start, size_t end,
	int (*cmp)(void *, void *))
{
	size_t		pivot;

	if (start >= end)
		return ;
	pivot = partition(tab, start, end, cmp);
	if (pivot)
		ft_quicksort(tab, start, pivot - 1, cmp);
	ft_quicksort(tab, pivot + 1, end, cmp);
}
