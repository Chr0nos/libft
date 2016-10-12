/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:44:34 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/07 03:17:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	p;
	int		miss;

	p = 0;
	while ((p < n) && (src[p] != '\0'))
	{
		dest[p] = src[p];
		p++;
	}
	miss = (int)(n - p);
	if (miss > 0)
		ft_bzero(&dest[p], (size_t)miss);
	return (dest);
}
