/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:30:04 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 19:24:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_len(const char *s, const char *list)
{
	size_t		p;

	p = 0;
	while (*s)
		if (ft_strany(*(s++), list))
			p++;
	return (p);
}

char			*ft_strtrim(const char *s)
{
	const char		*skiplist = " \n\t";
	const size_t	len = ft_strtrim_len(s, skiplist);
	char			*x;

	if (!(x = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s)
	{
		if (!ft_strany(*s, skiplist))
			*(x++) = *s;
		s++;
	}
	*(++x) = '\0';
	return (x - len - 1);
}
