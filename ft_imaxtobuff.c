/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtobuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:47:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 01:49:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_imaxtobuff_len(intmax_t nb, int base)
{
	int			len;

	len = (nb < 0) ? 2 : 1;
	while ((nb) && (nb /= base))
		len++;
	return (len);
}

int			ft_imaxtobuff(char *buffer, intmax_t nb,
	int base, const char *map)
{
	int		len;
	int		p;

	if ((base > 62) || (base < 2))
		return (-1);
	len = ft_imaxtobuff_len(nb, base);
	p = len;
	buffer[p--] = '\0';
	if (nb < 0)
		buffer[0] = '-';
	else if (nb == 0)
		buffer[p] = map[0];
	while (nb)
	{
		buffer[p--] = map[(uintmax_t)((nb < 0) ? -nb : nb) % (unsigned)base];
		nb /= base;
	}
	return (len);
}
