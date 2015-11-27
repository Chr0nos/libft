/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:43:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 18:48:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(const char *str, const char *item, size_t n)
{
	size_t	p;

	if (!*item)
		return ((char*)str);
	while (*str)
	{
		p = 0;
		while ((str[p] == item[p]) && (n--))
			if (!item[p++])
				return ((char*)str);
		str++;
	}
	return (0);
}
