/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 20:11:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dest);
	const size_t	len = ft_strlen(src);
	size_t			copy;
	//size_t			p;

	//p = dlen;
	//while ((*src) && (p + 1 < size))
	//	dest[p++] = *(src++);
	//dest[p] = '\0';

	if (dlen + len > size - 1)
	{
		copy = size - dlen - 1;
		ft_memcpy(&dest[dlen], src, copy);
		dest[dlen + copy] = '\0';
	}
	else
		ft_memcpy(&dest[dlen], src, len + 1);
	return ((size < dlen) ? len + size : len + dlen);
}
