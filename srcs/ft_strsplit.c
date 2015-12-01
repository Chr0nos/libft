/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:27:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 03:31:04 by snicolet         ###   ########.fr       */
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
	return (0);
}

char	**ft_strsplit(char *str, char separator)
{
	size_t	len;
	size_t	space;
	char	**split;

	split = malloc(sizeof(char*) * (ft_strcount(str, separator) + 1));
	space = 0;
	while ((*str) && (len = ft_indexof(str, separator)) && (len))
	{
		split[space++] = ft_strndup(str, len);
		str += len + 1;
	}
	//split[space++] = ft_strdup(str);
	split[space] = 0;
	return (split);
}
