/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:44:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 13:48:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	p;

	p = 0;
	while ((p < n) && (src[p] != '\0'))
	{
		dest[p] = src[p];
		p++;
	}
	while (p < n)
		dest[p++] = '\0';
	return (dest);
}
