/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:27:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/02 12:25:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strsplit_seek_for_that_damn_separator(char **str, char c)
{
	size_t	seeks;

	seeks = 0;
	while ((**str == c)&& (seeks++))
		(*str)++;
	return (seeks);
}

static size_t	ft_strsplit_count(char *str, char c)
{
	size_t	len;

	len = ((*str) ? 1 : 0);
	while (*str)
	{
		if ((*str == c) && (++len))
			ft_strsplit_seek_for_that_damn_separator(&str, c);
		else
			str++;
	}
	return (len + 1);
}

char			**ft_strsplit(char *str, char separator)
{
	size_t	len;
	size_t	space;
	char	**split;

	if (!(split = malloc(sizeof(char*) * ft_strsplit_count(str, separator))))
		return (NULL);
	space = 0;
	while (*str)
	{
		ft_strsplit_seek_for_that_damn_separator(&str, separator);
		len = ft_strindexof(str, separator);
		if (len)
		{
			split[space++] = ft_strndup(str, len);
			str += len + 1;
		}
	}
	if (*str)
		split[space++] = ft_strdup(str);
	split[space] = 0;
	return (split);
}
