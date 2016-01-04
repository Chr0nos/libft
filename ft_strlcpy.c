/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:45:01 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/04 11:42:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			p;
	const size_t	len = ft_strlen(src);

	if (size < len)
		return (len);
	p = 0;
	while ((*src) && (p < len))
		dest[p++] = *(src++);
	dest[p] = '\0';
	return (len);
}
