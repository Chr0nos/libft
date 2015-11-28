/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 23:51:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dest);
	size_t			len;
	size_t			p;

	len = ft_strlen(src);
	if (len > size)
	len = size;
	if (len == size)
		return (len + size);
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
