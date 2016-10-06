/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:56 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/17 12:31:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		p;

	if (dest == src)
		return (dest);
	p = 0;
	while ((p < size) && ((size - p) % 8))
	{
		((unsigned char *)(dest))[p] = ((const unsigned char *)(src))[p];
		p++;
	}
	while (p < size)
	{
		*(unsigned long *)((unsigned long)dest + p) =
			*(unsigned long *)((unsigned long)src + p);
		p += 8;
	}
	return (dest);
}
