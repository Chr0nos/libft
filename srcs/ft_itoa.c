/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 19:39:09 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 14:04:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "unistd.h"

char	*ft_itoa(int nb)
{
	size_t		p;
	const char	*map = "0123456789";
	char		*buffer;

	buffer = malloc(sizeof(char) * 12);
	p = 0;
	if (nb == 0)
		buffer[p++] = '0';
	else if (nb < 0)
		buffer[p++] = '-';
	while (nb != 0)
	{
		buffer[p++] = map[nb * ((nb < 0) ? -1 : 1) % 10];
		nb /= 10;
	}
	buffer[p] = '\0';
	if (buffer[0] == '-')
		ft_strrev(buffer + 1);
	else
		ft_strrev(buffer);
	return (buffer);
}
