/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:14:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/13 13:55:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*x;
	const unsigned char	*y;
	size_t				p;

	x = s1;
	y = s2;
	p = 0;
	while ((p < n) && (x[p] == y[p]))
		p++;
	return ((p == n) ? 0 : x[p] - y[p]);
}
