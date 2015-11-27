/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 00:35:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	p;

	len = ft_strlen((char*)src);
	if (len > size)
		len = size;
	while (*dest)
	{
		len++;
		dest++;
	}
	p = 0;
	while ((src[p]) && (len < size - 1))
	{
		dest[p] = src[p];
		len++;
		p++;
	}
	if (len < size)
		dest[p] = '\0';
	return (len);
}
