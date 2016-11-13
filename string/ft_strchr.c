/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:23:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/13 00:51:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strchr(char *str, int c)
{
	const char		*s = str;
	const size_t	*lptr = (const unsigned long *)(size_t)s;
	size_t			pattern;

	while ((unsigned long int)s & (sizeof(long) - 1))
	{
		IFRET__(*s == c, (char *)(size_t)s);
		IFRET__(!*(s++), NULL);
	}
	pattern = (unsigned char)c | (unsigned char)(c << 8);
	pattern |= (pattern << 16) | (pattern << 32) | (pattern << 48);
	while (42)
	{
		if (LONGCHR(*lptr, pattern))
		{
			IFRET__(*(s = (const char *)lptr) == c, (char *)(size_t)s);
			EIFRET__(s[1] == c && ft_strlen(s) >= 1, (char *)(size_t)&s[1]);
			EIFRET__(s[2] == c && ft_strlen(s) >= 2, (char *)(size_t)&s[2]);
			EIFRET__(s[3] == c && ft_strlen(s) >= 3, (char *)(size_t)&s[3]);
			EIFRET__(s[4] == c && ft_strlen(s) >= 4, (char *)(size_t)&s[4]);
			EIFRET__(s[5] == c && ft_strlen(s) >= 5, (char *)(size_t)&s[5]);
			EIFRET__(s[6] == c && ft_strlen(s) >= 6, (char *)(size_t)&s[6]);
			EIFRET__(s[7] == c && ft_strlen(s) >= 7, (char *)(size_t)&s[7]);
			ERET__(NULL);
		}
		IFRET__(LONGCHR_NULL(*(lptr++)), NULL);
	}
}

char					*ft_strchr_old(char *s, int c)
{
	while ((*s) && (*s != (char)c))
		s++;
	return ((*s == c) ? s : NULL);
}
