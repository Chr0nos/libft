/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 18:41:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	p;

	if (!size)
		return (0);
	size--;
	len = ft_strlen((char*)src);
	if (len > size)
		len = size;
	while ((*dest) && (dest++))
		len++;
	p = 0;
	while ((src[p]) && (len + p < size))
	{
		dest[p] = src[p];
		p++;
	}
	dest[p++] = '\0';
	return (len + p);
}
