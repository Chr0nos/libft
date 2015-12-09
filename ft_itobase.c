/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:01:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 16:08:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
