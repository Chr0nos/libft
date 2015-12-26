/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:34:00 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 15:59:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *ptr)
{
	const char		*map = "0123456789abcdef";
	char			buffer[16];
	char			*wbuffer;
	unsigned int	p;
	unsigned short	part;

	if (!ptr)
	{
		ft_putstr("0x0");
		return ;
	}
	p = 1;
	ft_putstr("0x");
	buffer[0] = '\0';
	wbuffer = (char*)buffer;
	while (p < sizeof(ptr) / sizeof(unsigned short))
	{
		part = (unsigned short)((unsigned long)ptr >> ((15 - p) * 16));
		ft_itobase((int)part, wbuffer, 16, map);
		wbuffer += ft_strlen(wbuffer);
		p++;
	}
	ft_putstr(buffer);
}
