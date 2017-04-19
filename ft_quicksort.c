/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 16:35:54 by snicolet          #+#    #+#             */
/*   Updated: 2017/04/19 20:19:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_quicksort_part(void **tab, size_t start, size_t end,
		int (*cmp)(void *, void *))
{
	void	*pivot;

	pivot = tab[start];
	while (1)
	{
		while (((*cmp)(tab[end], pivot) >= 0) && (start < end))
			end--;
		while ((*cmp)(tab[start], pivot) < 0)
			start++;
		if (start < end)
			ft_swap_ptr(&tab[start], &tab[end]);
		else
			return (end);
	}
}

void			ft_quicksort(void **tab, size_t start, size_t end,
	int (*cmp)(void *, void *))
{
	size_t		subend;

	if (start < end)
	{
		subend = ft_quicksort_part(tab, start, end - 1, cmp);
		ft_quicksort(tab, start, subend, cmp);
		ft_quicksort(tab, subend + 1, end, cmp);
	}
}
