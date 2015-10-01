/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 17:10:26 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/26 16:05:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puthex(void *data, t_size size)
{
	unsigned char	*c;
	char			buffer[4];
	unsigned int	p;
	unsigned int	block;

	p = 0;
	c = data;
	while (p < size)
	{
		ft_itoa(c[size - 1 - p], (char *)buffer, 16);
		ft_putstr_align_right(buffer, '0', 2);
		if (p + 1 < size)
			ft_putchar(' ');
		p++;
		block = (size - p < 16) ? size - p : 16;
		(void)block;
	}
}

