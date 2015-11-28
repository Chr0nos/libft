/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:39:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 22:15:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	n = ft_strlen((char*)s);
	if (!c)
		return (((char*)(s + n)));
	while (s[--n])
	{
		if (s[n] == (unsigned char)c)
			return ((char*)&s[n]);
	}
	return (NULL);
}
