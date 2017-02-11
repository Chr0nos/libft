/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:37:34 by snicolet          #+#    #+#             */
/*   Updated: 2017/02/11 10:26:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t				ft_strwordlen(const char *str)
{
	const char	*start = str;

	while ((*str) && (!ft_strany(*str, " \t\v\n\r")))
		str++;
	return ((size_t)str - (size_t)start);
}

int							ft_scanf_set_word(t_scanf *sf)
{
	size_t		len;
	char		**str;

	len = ft_strwordlen(sf->str);
	if ((sf->flags & FT_SF_FLAG_PREC) && (len > (size_t)sf->precision))
		len = (size_t)sf->precision;
	if (!(sf->flags & FT_SF_FLAG_SKIP))
	{
		str = va_arg(*sf->ap, char **);
		if (!(*str = malloc(sizeof(char) * (len + 1))))
		{
			sf->flags |= FT_SF_ERROR | FT_SF_QUIT;
			return (1);
		}
		(*str)[len] = '\0';
		ft_memcpy(*str, sf->str, len);
	}
	sf->str += len;
	return (1);
}
