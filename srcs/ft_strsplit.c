/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:27:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/02 15:57:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strsplit_count(const char *str, char c)
{
	size_t	len;

	len = 0;
	while ((*str) && (++len))
	{
		while (*str == c)
			str++;
		if (!*str)
			return (len + 1);
		else
			str++;
	}
	return (len + 1);
}

char			**ft_strsplit(const char *str, char separator)
{
	char	**split;
	size_t	len;
	size_t	space;

	if (!(split = malloc(sizeof(char*) * ft_strsplit_count(str, separator))))
		return (NULL);
	space = 0;
	while (*str)
	{
		while (*str == separator)
			str++;
		if (*str)
		{
			len = ft_strsublen(str, separator);
			split[space++] = ft_strndup(str, len);
			str += len;
		}
	}
	split[space] = 0;
	return (split);
}
