/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:56 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 13:12:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				p;

	p = 0;
	while (p < size)
	{
		((unsigned char *)(dest))[p] = ((const unsigned char *)(src))[p];
		p++;
	}
	return (dest);
}
