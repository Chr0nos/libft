/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:00 by snicolet          #+#    #+#             */
/*   Updated: 2017/01/04 11:39:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			p;
	const size_t	blk = LONGIFY(INTIFY(SHORTIFY((unsigned char)c)));

	p = 0;
	while ((p < n) && ((n - p) % 8))
		((unsigned char *)(dest))[p++] = (unsigned char)c;
	while (p < n)
	{
		*(unsigned long*)((unsigned long)dest + p) = blk;
		p += 8;
	}
	return (dest);
}
