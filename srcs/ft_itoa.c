/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 19:39:09 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 20:33:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "string.h"

char		*ft_itoa(int nb)
{
	size_t		p;
	const char	*map = "0123456789";
	char		*buffer;

	(void)map;
	buffer = malloc(sizeof(char) * 12);
	p = 0;
	if (nb == 0)
		buffer[p++] = '0';
	else if (nb < 0)
	{
		buffer[p++] = '-';
		nb *= -1;
	}
	while (nb)
	{
		//buffer[p++] = map[nb * ((nb < 0) ? -1 : 1) % 10];
		buffer[p++] = (nb % 10) + '0';
		nb /= 10;
	}
	buffer[p] = '\0';
	ft_strrev(buffer + ((buffer[0] == '-') ? 1 : 0));
	return (buffer);
}
