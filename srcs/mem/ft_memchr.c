/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:40:30 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/24 14:56:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				p;
	const unsigned char	*x;

	x = s;
	p = 0;
	while (p < n)
	{
		if (x[p] == c)
			return ((char*)x + p);
		p++;
	}
	return (0);
}
