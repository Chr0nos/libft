/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 13:45:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static size_t	ft_max(size_t nb, size_t max)
{
	return (nb > max ? max : nb);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dlen = ft_max(ft_strlen(dest), size);
	const size_t	len = ft_strlen(src);
	size_t			p;

	if (dlen == size--)
		return (dlen + size + 1);
	dest += dlen;
	p = 0;
	while (p < size - dlen)
	{
		dest[p] = src[p];
		p++;
	}
	dest[p] = '\0';
	return (len + dlen);
}
