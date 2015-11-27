/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 09:30:35 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 11:12:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_table(int *tab, int size)
{
	int		p;
	int		tmp;

	p = 0;
	while (p < size - 1)
	{
		if (tab[p] > tab[p + 1])
		{
			tmp = tab[p];
			tab[p] = tab[p + 1];
			tab[p + 1] = tmp;
			p = 0;
		}
		else
			p++;
	}
}
