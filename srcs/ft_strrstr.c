/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 00:13:17 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:53:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_is_same(const char a, const char b)
{
	if (a == b)
		return (1);
	if ((a >= 'A') && (a <= 'Z') && (a + 'a' - 'A' == b))
		return (1);
	return (0);
}

char		*ft_strrstr(const char *str, const char *item)
{
	size_t	p;

	if (!*item)
		return ((char*)str);
	while (*str)
	{
		p = 0;
		while (ft_is_same(str[p], item[p]))
			if (!item[p++])
				return ((char*)str);
		str++;
	}
	return (0);
}
