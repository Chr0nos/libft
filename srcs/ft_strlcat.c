/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 14:33:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

static size_t	ft_max(size_t nb, size_t max)
{
	return (nb > max ? max : nb);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dest);
	size_t			len;
	size_t			p;

	len = ft_max(ft_strlen(src), size);
	if (len == size)
		return (len + dlen);
	dest += dlen;
	p = 0;
	while ((src[p]) && (p < size - len - 1))
	{
		dest[p] = src[p];
		p++;
	}
	dest[p++] = '\0';
	return (len + dlen);
}
