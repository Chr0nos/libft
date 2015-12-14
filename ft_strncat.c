/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:29:12 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 14:00:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t			p;

	p = ft_strlen(dest);
	while ((*src != '\0') && (n--))
	{
		dest[p++] = *src;
		src++;
	}
	dest[p] = '\0';
	return (dest);
}
