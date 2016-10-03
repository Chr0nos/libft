/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:14:34 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 17:16:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			p;
	int				ret;

	p = 0;
	while ((p < n) && ((n - p) % 8))
	{
		if ((ret = *(const unsigned char *)((size_t)s1 + p) -
			*(const unsigned char *)((size_t)s2 + p)) != 0)
			return (ret);
		p++;
	}
	while (p < n)
	{
		if (*(const unsigned long *)((size_t)s1 + p) !=
				*(const unsigned long *)((size_t)s2 + p))
		{
			return (ft_memcmp((const void*)((size_t)s1 + p),
						(const void*)((size_t)s2 + p), n - p + 1));
		}
		p += 8;
	}
	return (0);
}
