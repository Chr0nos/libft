/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 19:39:09 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/26 11:57:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_itoa(int nb, char *buffer)
{
	int			p;
	const char	*map = "0123456789";

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
