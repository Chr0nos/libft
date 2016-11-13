/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:23:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/13 21:54:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline char		*ft_strchr_test(const char *s, int c)
{
	IFRET__(s[0] == c, (char *)(size_t)s);
	EIFRET__(!s[0], NULL);
	EIFRET__(s[1] == c, (char *)(size_t)&s[1]);
	EIFRET__(!s[1], NULL);
	EIFRET__(s[2] == c, (char *)(size_t)&s[2]);
	EIFRET__(!s[2], NULL);
	EIFRET__(s[3] == c, (char *)(size_t)&s[3]);
	EIFRET__(!s[3], NULL);
	EIFRET__(s[4] == c, (char *)(size_t)&s[4]);
	EIFRET__(!s[4], NULL);
	EIFRET__(s[5] == c, (char *)(size_t)&s[5]);
	EIFRET__(!s[5], NULL);
	EIFRET__(s[6] == c, (char *)(size_t)&s[6]);
	EIFRET__(!s[6], NULL);
	EIFRET__(s[7] == c, (char *)(size_t)&s[7]);
	ERET__(NULL);
}

char					*ft_strchr(char *str, int c)
{
	const char		*s = str;
	const size_t	*lptr;
	const size_t	pattern = LONGIFY(INTIFY(SHORTIFY(c)));

	IFRET__(!c, str + ft_strlen(str));
	while ((unsigned long int)s & (sizeof(long) - 1))
	{
		IFRET__(*s == c, (char *)(size_t)s);
		IFRET__(!*(s++), NULL);
	}
	lptr = (const unsigned long *)(size_t)s;
	while (42)
	{
		s = (const char *)lptr;
		IFRET__((LONGCHR_NULL(*lptr)), ft_strchr_test(s, c));
		if (LONGCHR_NULL((*lptr ^ pattern)))
			return (ft_strchr_test(s, c));
		lptr++;
	}
}

char					*ft_strchr_old(char *s, int c)
{
	while ((*s) && (*s != (char)c))
		s++;
	return ((*s == c) ? s : NULL);
}
