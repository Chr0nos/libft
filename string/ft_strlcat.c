/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 14:10:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dest);
	const size_t	len = ft_strlen(src);
	size_t			total;
	size_t			p;

	if (size < dlen)
		total = len + size;
	else
		total = len + dlen;
	p = dlen;
	while ((*src) && (p + 1 < size))
		dest[p++] = *(src++);
	dest[p] = '\0';
	return (total);
}
