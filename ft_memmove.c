/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:40:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 16:05:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if ((dest < src) || (dest > (void*)((unsigned long)src + n)))
		return (ft_memcpy(dest, src, n));
	while (n--)
		((unsigned char *)(dest))[n] = ((const unsigned char *)(src))[n];
	return (dest);
}
