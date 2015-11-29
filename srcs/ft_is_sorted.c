/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 13:43:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:49:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sorted_get_order(void **tab, size_t size, int (*cmp)())
{
	size_t	p;
	int		r;

	p = 0;
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

int			ft_is_sorted(void **tab, size_t size, int (*cmp)())
{
	size_t		p;
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
