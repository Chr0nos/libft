/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftobuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:48:05 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/24 15:21:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ftobuff(char *buffer, float nb, unsigned int base, const char *map)
{
	int		real;
	int		real_len;

	real = (int)nb;
	real_len = ft_itobuff(buffer, real, base, map);
	nb = ((nb) - (float)real) * 1000000;
	if ((int)nb)
	{
		buffer[real_len++] = '.';
		ft_itobuff(buffer + real_len, (int)((nb < 0) ? -nb : nb), base, map);
	}
	return (real_len);
}
