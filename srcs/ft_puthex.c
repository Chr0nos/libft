/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 17:10:26 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/23 21:47:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(void *data, t_size size)
{
	unsigned char	*c;
	char			buffer[4];
	unsigned int	p;
	unsigned int	block;
	const char		*pattern = "0123456789abcdef";

	p = 0;
	c = data;
	while (p < size)
	{
		ft_itobase(c[size - 1 - p], (char *)buffer, 16, pattern);
		ft_putstr_align_right(buffer, '0', 2);
		if (p + 1 < size)
			ft_putchar(' ');
		p++;
		block = (size - p < 16) ? size - p : 16;
		(void)block;
	}
}

