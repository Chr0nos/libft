/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:03:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/05 18:43:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strappend(char **s1, const char *s2)
{
	size_t			size;
	char			*d;
	size_t			p;
	size_t			i;

	p = 0;
	size = ((*s1) ? ft_strlen(*s1) : 0) + ft_strlen(s2);
	if ((d = (char*)malloc(sizeof(char) * (size + 1))))
	{
		i = 0;
		if (*s1)
		{
			while ((*s1)[i] != '\0')
				d[p++] = (*s1)[i++];
			free(*s1);
			*s1 = 0;
		}
		while (*s2)
			d[p++] = *(s2++);
		d[p] = '\0';
		*s1 = d;
	}
	else
		*s1 = 0;
	return (d);
}
