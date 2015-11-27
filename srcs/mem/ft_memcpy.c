/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:56 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 17:54:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				p;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	p = 0;
	while (p < size)
	{
		d[p] = s[p];
		p++;
	}
	return (dest);
}
