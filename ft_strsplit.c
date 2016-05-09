/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:27:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/09 19:30:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
			if ((split[space] = malloc(sizeof(char) * (len + 1))))
			{
				ft_memcpy(split[space], str, len);
				split[space][len] = '\0';
				space++;
			}
			str += len;
		}
	}
	split[space] = 0;
	return (split);
}
