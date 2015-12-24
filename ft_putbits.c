/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:23:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/24 16:50:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void		ft_putobits(unsigned char x, char *buffer)
{
	unsigned int	p;

	p = 0;
	while (p < 8)
	{
		buffer[p] = ((x & (1u << (7 - p))) ? '1' : '0');
		++p;
	}
	buffer[p] = '\0';
}

void			ft_putbits(void *data, size_t size)
{
	unsigned long	p;
	char			buffer[10];

	p = 0;
	while (p < size)
	{
		ft_putobits(*(unsigned char *)((unsigned long)data + p), buffer);
		p++;
		if (p != size)
			ft_strcpy(&buffer[8], " ");
		ft_putstr(buffer);
	}
	ft_putchar('\n');
}
