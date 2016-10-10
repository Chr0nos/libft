/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtobuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 21:59:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/11 00:23:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dtobuff_fast(char *buff, unsigned long *nb,
	unsigned int precision)
{
	unsigned long		conv;
//	const int			deca = ()

	(void)precision;
	conv = ((*nb & 0xFFC0000000000000ul) >> 0);
	if (*nb & 0x8000000000000000ul)
		*(buff++) = '-';
	ft_ulltobuff(buff, conv, 10, "0123456789");
	return (0);
}

int				ft_dtobuff(char *buff, double nb, unsigned int precision)
{
	unsigned long	x;
	unsigned char	exposant;
	unsigned char	neg;

	(void)precision;
	x = *(unsigned long *)&nb;
	exposant = (unsigned char)((x & 0x7F80000000000000ul) >> 53);
	neg = (x & 0x8000000000000000ul) ? 1 : 0;
	x &= ~0xFF80000000000000ul;
	if (exposant < 64)
		ft_dtobuff_fast(buff, (unsigned long *)&nb, precision);
	return ((int)precision);
}
