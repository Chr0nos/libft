/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:10:36 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 17:05:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	const size_t	len1 = ft_strlen(s1);
	const size_t	len2 = ft_strlen(s2);
	const size_t	size = len1 + len2;
	char			*x;

	if (!(x = malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_memcpy(x, s1, len1);
	ft_memcpy(x + len1, s2, len2);
	x[size] = '\0';
	return (x);
}
