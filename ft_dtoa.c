/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 22:01:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/09 05:43:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int		ft_dtoa_len(double nb, unsigned int precision)
{
	unsigned int	len;
	double			x;

	len = 1;
	x = nb;
	if (x < 1.0)
		len++;
	while (x >= 1)
	{
		len++;
		x /= 10.0;
	}
	return (len + precision + 1);
}

static void				ft_dtoa_dot(char *buffer, double nb,
	unsigned int precision, const char *map)
{
	long	x;

	if (!precision)
		return ;
	*(buffer++) = '.';
	nb -= (double)((__int128)nb);
	x = (long)(nb * ft_pow(10, (int)precision));
	while (precision--)
	{
		buffer[precision] = map[x % 10];
		x /= 10;
	}
}

char					*ft_dtoa(double nb, unsigned int precision)
{
	char			*buffer;
	const char		negative = (nb < 0.0 || *((long *)&nb) < 0) ? 1 : 0;
	unsigned int	len;
	const char		*map = "0123456789";

	if (negative)
		nb = -nb;
	len = ft_dtoa_len(nb, precision) + (unsigned int)negative -
		((!precision) ? 1 : 0);
	if (!(buffer = malloc(sizeof(char) * len)))
		return (NULL);
	buffer[--len] = '\0';
	if (precision)
		len -= precision + 1;
	ft_dtoa_dot(buffer + len, nb, precision, map);
	if (nb < 1.0)
		buffer[--len] = '0';
	while (nb >= 1.0)
	{
		buffer[--len] = map[(unsigned int)nb % 10];
		nb /= 10.0;
	}
	if (negative)
		buffer[0] = '-';
	return (buffer);
}
