/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 13:43:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/04 02:07:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_is_sorted_get_order(void  **tab, t_size size, int (*cmp)())
{
	t_size	p;
	int		r;

	p = 0;
	size--;
	while (p < size)
	{
		r = (*cmp)(tab[p], tab[p + 1]);
		if (r == 0)
			p++;
		else if (r > 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

int		ft_is_sorted(void **tab, t_size size, int (*cmp)())
{
	t_size		p;
	int			order;

	if (size < 2)
		return (1);
	p = 0;
	size--;
	order = ft_is_sorted_get_order(tab, size, cmp);
	while (p < size)
	{
		if (order == 0)
		{
			if ((*cmp)(tab[p], tab[p + 1]) > 0)
				return (0);
		}
		else if ((*cmp)(tab[p], tab[p + 1]) < 0)
			return (0);
		p++;
	}
	return (1);
}
