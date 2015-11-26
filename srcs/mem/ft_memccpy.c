/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:18:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/24 13:34:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int			p;
	unsigned const char		*s;
	unsigned char			*d;

	s = src;
	d = dest;
	p = 0;
	while (p < n)
	{
		d[p] = s[p];
		if (s[p] == c)
			return (d + p);
		p++;
	}
	return (0);
}