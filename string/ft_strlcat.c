/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/12/11 02:47:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dest);
	const size_t	len = ft_strlen(src);
	const size_t	p = (size - dlen - 1 < len) ? size - dlen - 1 : len;

	((char *)ft_memcpy(&dest[dlen], src, p))[p] = '\0';
	return ((size < dlen) ? len + size : len + dlen);
}
