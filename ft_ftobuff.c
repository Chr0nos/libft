/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftobuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:48:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 14:51:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ftobuff(char *buffer, double nb, unsigned int base, const char *map)
{
	int				real;
	int				real_len;
	unsigned int	digit;
	unsigned int	x;

	if ((nb < 0.0f) && (nb > -1.0f))
	{
		buffer[0] = '-';
		buffer++;
	}
	real = (int)nb;
	real_len = ft_itobuff(buffer, real, base, map);
	buffer[real_len++] = '.';
	digit = 0;
	while (digit < 12)
	{
		x = (unsigned int)(((nb < 0) ? -nb : nb) * (double)(base * digit));
		buffer[real_len++] = map[x % base];
		digit++;
	}
	buffer[real_len++] = '\0';
	return (real_len);
}
