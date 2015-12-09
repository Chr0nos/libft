/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:43:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 13:32:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const size_t	len = ft_strlen(s2);

	if (!*s2)
		return ((char*)s1);
	while ((*s1) && (n-- >= len))
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
