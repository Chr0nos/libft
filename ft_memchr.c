/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:40:30 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:38:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				p;
	const unsigned char	*x;

	x = s;
	p = 0;
	while (p < n)
	{
		if (x[p] == (const unsigned char)c)
			return ((char*)x + p);
		p++;
	}
	return (0);
}
