/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:23:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/22 15:17:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putbits(void *data, unsigned int size)
{
	unsigned int	p;
	unsigned int	*x;

	x = data;
	p = 0;
	while (p < size)
	{
		if (*x & (1u << (size - 1 - p)))
			ft_putchar('1');
		else
			ft_putchar('0');
		p++;
	}
}
