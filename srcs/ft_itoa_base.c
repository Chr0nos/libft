/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:09:13 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/08 13:09:25 by snicolet         ###   ########.fr       */
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

char		*ft_itoa_base(int value, int base)
{
	char			*buffer;
	unsigned int	len;
	char			sign;
	const char		*map = "0123456789ABCDEF";

	if ((base < 2) || (base > 16))
		return (0);
	if ((value < 0) && (base != 10))
		value = (unsigned int)-value;
	len = itoa_len(value, base);
	if (!(buffer = malloc(sizeof(char) * (len + 1))))
		return (0);
	sign = (value < 0) ? 1 : 0;
	buffer[len--] = '\0';
	if (!value)
		buffer[len--] = '0';
	while (value)
	{
		buffer[len--] = map[((value < 0) ? (unsigned int)-value : value) % base];
		value /= base;
	}
	if ((sign) && (base == 10))
		buffer[0] = '-';
	return (buffer);
}
