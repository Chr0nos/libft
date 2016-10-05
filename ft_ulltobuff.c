/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltobuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:34:14 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 02:29:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ulltobuff_len(unsigned long long nb, unsigned long long base)
{
	int			len;

	len = 1;
	while ((nb) && (nb /= base))
		len++;
	return (len);
}

int			ft_ulltobuff(char *buffer, unsigned long long nb, unsigned int base,
	const char *map)
{
	int		len;
	int		p;

	if ((base > 62) || (base < 2))
		return (-1);
	len = ft_ulltobuff_len(nb, (unsigned long long)base);
	p = len;
	buffer[p--] = '\0';
	if (nb == 0)
		buffer[p] = map[0];
	while (nb)
	{
		buffer[p--] = map[(unsigned long long)nb % base];
		nb /= (unsigned long long)base;
	}
	return (len);
}
