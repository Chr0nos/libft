/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:27:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 02:43:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_indexof(const char *str, char c)
{
	size_t	p;

	p = 0;
	while (str[p])
	{
		if (str[p] == c)
			return (p);
		p++;
	}
	return (p);
}

char	**ft_strsplit(char *str, char separator)
{
	size_t	space;
	char	**split;

	split = malloc(sizeof(char*) * (ft_strcount(str, separator) + 1));
	space = 0;
	while (*str)
	{
		if (*str == separator)
		{
			str++;
			if (!*str)
				return (split);
			split[space] = ft_strndup(str, ft_indexof(str, separator));
			space++;
		}
		str++;
	}
	split[space] = 0;
	return (split);
}
