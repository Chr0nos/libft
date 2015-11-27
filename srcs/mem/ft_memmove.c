/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:40:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 17:53:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if ((dest < src) || (dest > src + n))
		return (ft_memcpy(dest, (void*)src, n));
	s = src;
	d = dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
