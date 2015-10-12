/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 16:35:54 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/12 18:29:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_quicksort.h"

t_size	ft_quicksort_part(void **tab, t_size start, t_size end, int (*cmp)())
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

void	ft_quicksort(void **tab, t_size start, t_size end, int (*cmp)())
{
	t_size		subend;

	if (start < end)
	{
		subend = ft_quicksort_part(tab, start, end - 1, cmp);
		ft_quicksort(tab, start, subend, cmp);
		ft_quicksort(tab, subend + 1, end, cmp);
	}
}
