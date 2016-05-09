/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:15:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/09 18:30:11 by snicolet         ###   ########.fr       */
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
		while (ft_strany_string(str, separators))
			str++;
		if (*str)
		{
			len = ft_strsublenstr(str, separators);
			split[space++] = ft_memdup(str, len + 1);
			str += len;
		}
	}
	split[space] = NULL;
	return (split);
}
