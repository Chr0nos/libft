/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 16:35:54 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/08 18:19:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_quicksort.h"

t_size	ft_quicksort_part(t_quicksort *s, t_size start, t_size end)
{
	void	*pivot;

	pivot = s->tab[start];
	while (1)
	{
		while ((*s->cmp)(s->tab[end], pivot) > 0)
			end--;
		while ((*s->cmp)(s->tab[start], pivot) < 0)
			start++;
		if (start < end)
			ft_swap_ptr(s->tab[start], s->tab[end]);
		else
			return (start);
	}
}

void	ft_quicksort(void **tab, t_size start, t_size end, int (*cmp)())
{
	t_quicksort	s;
	t_size		subend;

	s.cmp = cmp;
	s.tab = tab;
	if (start < end)
	{
		subend = ft_quicksort_part(&s, start, end);
		ft_quicksort(tab, start, subend, cmp);
		ft_quicksort(tab, subend + 1, end, cmp);
	}
}
