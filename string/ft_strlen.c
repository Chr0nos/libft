/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:04:03 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 03:04:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlen(const char *str)
{
	const unsigned long		*x;
	const char				*cp = str;

	while ((unsigned long int)cp & (sizeof(long) - 1))
	{
		if (!*cp)
			return ((size_t)cp - (size_t)str);
		cp++;
	}
	x = (const unsigned long*)(unsigned long)cp;
	while (42)
	{
		if (LONGCHR_NULL(*(x++)))
		{
			cp = (const char *)(x - 1);
			IFRET__(!cp[0], (size_t)(cp - str));
			IFRET__(!cp[1], (size_t)(cp - str + 1));
			IFRET__(!cp[2], (size_t)(cp - str + 2));
			IFRET__(!cp[3], (size_t)(cp - str + 3));
			IFRET__(!cp[4], (size_t)(cp - str + 4));
			IFRET__(!cp[5], (size_t)(cp - str + 5));
			IFRET__(!cp[6], (size_t)(cp - str + 6));
			IFRET__(!cp[7], (size_t)(cp - str + 7));
		}
	}
}

size_t	ft_strplen(const char *str, const char *maxptr)
{
	const char	*origin = str;

	while ((*str) && (str < maxptr))
		str++;
	return ((size_t)str - (size_t)origin);
}
