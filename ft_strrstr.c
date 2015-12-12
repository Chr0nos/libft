/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:13:17 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:06:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_is_same(const char a, const char b)
{
	if (a == b)
		return (1);
	if ((a >= 'A') && (a <= 'Z') && (a + 'a' - 'A' == b))
		return (1);
	return (0);
}

char		*ft_strrstr(char *str, const char *item)
{
	size_t	p;

	if (!*item)
		return (str);
	while (*str)
	{
		p = 0;
		while (ft_is_same(str[p], item[p]))
			if (!item[p++])
				return (str);
		str++;
	}
	return (0);
}
