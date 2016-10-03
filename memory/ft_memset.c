/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/11 19:45:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			p;
	unsigned long	blk;

	p = 0;
	while ((p < n) && ((n - p) % 8))
		((unsigned char *)(dest))[p++] = (unsigned char)c;
	blk = (unsigned long)c | (unsigned long)(c << 8);
	blk |= blk << 16;
	blk |= blk << 32;
	while (p < n)
	{
		*(unsigned long*)((unsigned long)dest + p) = blk;
		p += 8;
	}
	return (dest);
}
