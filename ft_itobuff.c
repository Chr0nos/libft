/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:00:09 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/11 15:00:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itobuff_len(int nb, int base)
{
	int			len;

	len = 1;
	if (nb < 0)
		len++;
	while ((nb) && (nb /= base))
		len++;
	return (len);
}

int			ft_itobuff(char *buffer, int nb, unsigned int base, const char *map)
{
	int		len;
	int		p;

	if ((base > 62) || (base < 2))
		return (-1);
	len = itobuff_len(nb, (int)base);
	p = len;
	buffer[p--] = '\0';
	if (nb < 0)
		buffer[0] = '-';
	else if (nb == 0)
		buffer[p] = map[0];
	while (nb)
	{
		buffer[p--] = map[((nb < 0) ? (unsigned int)-nb : (unsigned)nb) % base];
		nb /= (int)base;
	}
	return (len);
}
