/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/25 01:58:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	p;

	len = ft_strlen((char*)src);
	if (len > size)
		len = size;
	while (*dst)
	{
		len++;
		dst++;
	}
	p = 0;
	while ((src[p]) && (len < size - 1))
	{
		dst[p] = src[p];
		p++;
	}
	if (p < size)
		dst[p] = '\0';
	return (len);
}
