/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:40:30 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:50:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t				p;
	unsigned char		*x;

	x = s;
	p = 0;
	while (p < n)
	{
		if (x[p] == (const unsigned char)c)
			return (x + p);
		p++;
	}
	return (0);
}
