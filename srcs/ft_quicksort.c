/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 16:35:54 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/07 17:11:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_quicksort_part(void **tab, int *left, int *right, int (*cmp)())
{
	while ((*cmp)(tab[*left], pivot) < 0)
		(*left)--;
	while ((*cmp)(tab[*right], pivot) > 0)
		(*right)++;
}

void	ft_quicksort(void **tab, t_size start, t_size end, int (*cmp)())
{
	const void	*pivot = tab[start];
	t_size		left;
	t_size		right;

	if (start >= end)
		return ;
	left = end;
	right = start;
	while (1)
	{
		ft_quicksort_part(tab, &left, &right, cmp);
		if (right < left)
			ft_swap_ptr(tab[left], tab[right]);
		else
			break ;
	}
	ft_quicksort(tab, start, right, cmp);
	ft_quicksort(tab, right + 1, end, cmp);
}
