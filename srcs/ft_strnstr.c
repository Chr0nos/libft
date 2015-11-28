/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:43:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 14:15:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(const char *str, const char *item, size_t n)
{
	size_t	p;
	size_t	x;

	if (!*item)
		return ((char*)str);
	p = 0;
	while ((str[p]) && (n))
	{
		x = 0;
		while ((n--) && (str[p + x] == item[x]))
			x++;
		if (!item[x])
			return ((char*)&str[p]);
		p++;
	}
	return (NULL);
}
