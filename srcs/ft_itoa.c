/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 19:39:09 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 20:23:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "string.h"

static size_t	ft_itoa_len(int nb)
{
	size_t	p;

	p = ((nb < 0) ? 1 : 0);
	while (nb)
	{
		nb /= 10;
		p++;
	}
	return (p + 1);
}

char			*ft_itoa(int nb)
{
	size_t		p;
	const char	*map = "0123456789";
	char		*buffer;

	buffer = malloc(sizeof(char) * ft_itoa_len(nb));
	if (!buffer)
		return (NULL);
	p = 0;
	if (nb == 0)
		buffer[p++] = '0';
	else if (nb < 0)
		buffer[p++] = '-';
	while (nb)
	{
		buffer[p++] = map[(unsigned int)(nb * ((nb < 0) ? -1 : 1)) % 10];
		nb /= 10;
	}
	buffer[p] = '\0';
	ft_strrev(buffer + ((buffer[0] == '-') ? 1 : 0));
	return (buffer);
}
