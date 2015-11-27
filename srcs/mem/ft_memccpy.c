/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:18:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 17:39:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t					p;
	unsigned const char		*s;
	unsigned char			*d;

	s = src;
	d = dest;
	p = 0;
	while ((p < n) && (d[p] != (unsigned char)c))
	{
		d[p] = s[p];
		p++;
	}
	if (p == n)
		return (0);
	return (dest + p + 1);
}
