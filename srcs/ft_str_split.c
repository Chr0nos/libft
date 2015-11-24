/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:27:16 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/24 16:19:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_str_split(char *str, char separator)
{
	int				space;
	char			**split;
	unsigned int	len;

	split = malloc(sizeof(char*) * (ft_strcount(str, separator) + 1));
	space = 0;
	while (*str)
	{
		if (*str == ' ')
		{
			str++;
			if (!*str)
				return (split);
			len = ft_strsublen(str, separator);
			split[space] = malloc(sizeof(char) * (len + 1));
			ft_strncpy(split[space], str, len);
			split[space][len] = '\0';
			space++;
		}
		str++;
	}
	split[space] = 0;
	return (split);
}
