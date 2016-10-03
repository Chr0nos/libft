/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:15:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/09 19:34:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplitstr(const char *str, const char *separators)
{
	char		**split;
	size_t		len;
	size_t		space;

	if (!(split = malloc(sizeof(char*) *
					ft_strsplitstr_count(str, separators))))
		return (NULL);
	space = 0;
	while (*str)
	{
		while ((*str) && (ft_strany(*str, separators)))
			str++;
		if (*str)
		{
			len = ft_strsublenstr(str, separators);
			if (!(split[space] = malloc(sizeof(char) * (len + 1))))
				break ;
			ft_memcpy(split[space], str, len);
			split[space][len] = '\0';
			space++;
			str += len;
		}
	}
	split[space] = NULL;
	return (split);
}
