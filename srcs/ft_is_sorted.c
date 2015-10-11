/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 13:43:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/11 14:04:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_is_sorted(void **tab, t_size size, int (*cmp)())
{
	t_size		p;
	int			order;

	if (size < 2)
		return (1);
	p = 0;
	order = -1;
	size--;
	while (p < size)
	{
		if (order < 0)
			order = ((*cmp)(tab[p], tab[p + 1]) < 0 ? 0 : 1);
		else if (order == 0)
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
