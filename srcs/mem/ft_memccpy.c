/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:18:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 17:17:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t					p;
	unsigned const char		*s;
	unsigned char			*d;

	if (!n)
		return (NULL);
	s = src;
	d = dest;
	p = 0;
	while (p < n)
	{
		d[p] = s[p];
		if (d[p] == (unsigned char)c)
			return (dest + p + 1);
		p++;
	}
	return (NULL);
}
