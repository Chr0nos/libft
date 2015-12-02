/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:27:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/02 10:34:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char *str, char separator)
{
	size_t	len;
	size_t	space;
	char	**split;

	if (!(split = malloc(sizeof(char*) * (ft_strcount(str, separator) + 2))))
		return (NULL);
	space = 0;
	while ((*str) && (len = ft_strindexof(str, separator)))
	{
		split[space++] = ft_strndup(str, len);
		str += len + 1;
	}
	if (*str)
		split[space++] = ft_strdup(str);
	split[space] = 0;
	return (split);
}
