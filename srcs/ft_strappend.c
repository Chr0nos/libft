/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:03:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/05 22:11:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strappend(char **s1, const char *s2)
{
	const size_t	len1 = ((*s1) ? ft_strlen(*s1) : 0);
	const size_t	len2 = ft_strlen(s2);
	char			*d;

	if ((d = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
	{
		if (*s1)
		{
			ft_memcpy(d, *s1, len1);
			free(*s1);
		}
		ft_strncpy(d + len1, s2, len2 + 1);
		*s1 = d;
	}
	else
		*s1 = 0;
	return (d);
}
