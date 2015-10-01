/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 12:37:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/24 17:08:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putmem_ascii(void *data, unsigned int size)
{
	unsigned char	*x;
	unsigned int	p;

	x = data;
	p = 0;
	while (p < size)
	{
		ft_putchar((ft_is_printable(x[p])) ? x[p] : '.');
		p++;
	}
}

void	ft_putmem(void *data, t_size size)
{
	unsigned int	pos_bin;
	unsigned char	*x;
	unsigned int	block;
	unsigned int	bits_len;

	block = 4 * 8;
	pos_bin = 0;
	x = data;
	while (pos_bin < size)
	{
		bits_len = ((block > size - pos_bin) ? size - pos_bin : block);
		ft_putbits(&x[pos_bin], bits_len);
		ft_putchar(' ');
		ft_putmem_ascii(&x[pos_bin], bits_len / 8);
		ft_putchar('\n');
		pos_bin += block;
	}
}
