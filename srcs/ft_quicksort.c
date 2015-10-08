/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 16:35:54 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/08 16:27:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_quicksort.h"

void	ft_quicksort_part(t_quicksort *s)
{
	ft_putstr("partition: ");
	ft_putnbr(s->left);
	ft_putchar(' ');
	ft_putnbr(s->right);
	ft_putchar('\n');
	while ((*s->cmp)(s->tab[s->left], s->pivot) > 0)
		(s->left)--;
	while ((*s->cmp)(s->tab[s->right], s->pivot) < 0)
		(s->right)++;
}

void	ft_quicksort(void **tab, t_size start, t_size end, int (*cmp)())
{
	t_quicksort	s;

	if (start >= end)
		return ;
	s.pivot = tab[start];
	s.left = end - 1;
	s.right = start;
	s.cmp = cmp;
	s.tab = tab;
	while (s.right < s.left)
	{
		ft_quicksort_part(&s);
		if (s.right < s.left)
			ft_swap_ptr(tab[s.left], tab[s.right]);
	}
	ft_quicksort(tab, start, s.right, cmp);
	ft_quicksort(tab, s.right + 1, end, cmp);
}
