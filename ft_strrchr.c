/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:39:07 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:01:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(char *s, int c)
{
	size_t	n;

	n = ft_strlen(s);
	if (!c)
		return (((char*)(s + n)));
	while (n)
		if (s[--n] == (unsigned char)c)
			return ((char*)&s[n]);
	return (NULL);
}
