/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:40:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/13 18:19:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	void				*end;

	if (dest == src)
		return (dest);
	end = (void*)((unsigned long)src + n);
	if ((dest < src) || (dest > end))
		return (ft_memcpy(dest, src, n));
	s = src;
	d = dest;
	while (n-- != 0)
		d[n] = s[n];
	return (dest);
}
