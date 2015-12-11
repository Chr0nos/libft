/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 19:39:09 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/10 21:42:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	itoa_len(int nb)
{
	int		p;

	p = 1;
	if (nb < 0)
		p++;
	while ((nb) && (nb /= 10))
		p++;
	return (p);
}

char		*ft_itoa(int nbr)
{
	char			*buffer;
	unsigned int	len;
	char			sign;
	unsigned int	nb;

	len = itoa_len(nbr);
	if (!(buffer = malloc(sizeof(char) * (len + 1))))
		return (0);
	sign = (nbr < 0) ? 1 : 0;
	buffer[len--] = '\0';
	if (!nbr)
		buffer[len--] = '0';
	nb = ((nbr < 0) ? (unsigned int)-nbr : (unsigned int)nbr);
	while (nb)
	{
		buffer[len--] = '0' + (nb % 10);
		nb /= 10;
	}
	if (sign)
		buffer[0] = '-';
	return (buffer);
}