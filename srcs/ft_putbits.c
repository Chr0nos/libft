/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:23:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:40:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putobits(unsigned char *x)
{
	unsigned int	p;

	p = 0;
	while (p < 8)
	{
		ft_putchar((*x & (1u << (7 - p))) ? '1' : '0');
		p++;
	}
}

void			ft_putbits(void *data, unsigned int size)
{
	unsigned char	*x;
	unsigned int	p;

	size /= 8;
	x = data;
	p = 0;
	while (p < size)
	{
		ft_putobits(&x[size - 1 - p]);
		if (p + 1 < size)
			ft_putchar(' ');
		p++;
	}
}
