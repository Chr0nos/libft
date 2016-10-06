/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:18:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:46:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

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
		if (d[p++] == (unsigned char)c)
			return ((void*)((unsigned long)dest + (unsigned long)p));
	}
	return (NULL);
}
