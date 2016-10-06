/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:43:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:07:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(char *s1, const char *s2, size_t n)
{
	const size_t	len = ft_strlen(s2);

	if (!*s2)
		return (s1);
	while ((*s1) && (n-- >= len))
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return (s1);
		s1++;
	}
	return (NULL);
}
