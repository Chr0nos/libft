/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:29:12 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 17:34:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*start;
	size_t	size;

	if (dest == src)
		return (dest);
	start = dest;
	while (*(start++))
		;
	size = ft_strlen(src) + 1;
	if (size > n)
		size = n;
	ft_memcpy(start - 1, src, size);
	return (dest);
}
