/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:40:30 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/16 20:40:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					p;
	const unsigned char		*x;

	x = s;
	p = 0;
	while (p < n)
	{
		if (x[p] == (const unsigned char)c)
			return ((void*)((unsigned long)x + (unsigned long)p));
		p++;
	}
	return (0);
}
