/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 19:39:09 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 01:33:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_itoa(int nb)
{
	int			p;
	const char	*map = "0123456789";
	char		*buffer;

	buffer = malloc(sizeof(char) * 13);
	p = 0;
	if (nb == 0)
		buffer[p++] = '0';
	else if (nb < 0)
	{
		nb *= -1;
		buffer[p++] = '-';
	}
	while (nb)
	{
		buffer[p] = map[nb % 10];
		nb /= 10;
		p++;
	}
	buffer[p] = '\0';
	ft_strrev(buffer + ((buffer[0] == '-') ? 1 : 0));
	return (buffer);
}

char	*ft_itobase(int nb, char *buffer, unsigned char base, const char *map)
{
	int			p;

	if (base < 2)
		return (0);
	p = 0;
	if (nb == 0)
		buffer[p++] = '0';
	if (nb < 0)
	{
		buffer[p++] = '-';
		nb *= -1;
	}
	while (nb)
	{
		buffer[p] = map[nb % base];
		nb /= base;
		p++;
	}
	buffer[p] = '\0';
	ft_strrev(buffer + ((buffer[0] == '-') ? 1 : 0));
	return (buffer);
}
