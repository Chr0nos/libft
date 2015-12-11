/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:09:13 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/11 14:29:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	itoa_len(int nb, int base)
{
	int		p;

	p = 1;
	if ((nb < 0) && (base == 10))
		p++;
	while ((nb) && (nb /= base))
		p++;
	return (p);
}

char		*ft_itoa_base(int val, int base)
{
	char			*buffer;
	unsigned int	len;
	char			sign;
	const char		*map = "0123456789ABCDEF";
	unsigned int	nb;

	if ((base < 2) || (base > 16))
		return (0);
	if ((val < 0) && (base != 10))
		val = (unsigned int)-val;
	len = itoa_len(val, base);
	if (!(buffer = malloc(sizeof(char) * (len + 1))))
		return (0);
	sign = (val < 0) ? 1 : 0;
	nb = ((val < 0) ? (unsigned int)-val : (unsigned int)val);
	buffer[len--] = '\0';
	if (!nb)
		buffer[len--] = '0';
	while ((nb) && (buffer[len--] = map[nb % base]))
		nb /= base;
	if ((sign) && (base == 10))
		buffer[0] = '-';
	return (buffer);
}
