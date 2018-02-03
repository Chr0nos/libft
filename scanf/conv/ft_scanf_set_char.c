/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:20:46 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/03 13:46:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_scanf_set_char(t_scanf *sf)
{
	char			*str;
	size_t			maxlen;
	size_t			len;

	if (sf->flags & FT_SF_MOD_HASH)
		return (ft_scanf_set_str(sf));
	maxlen = (sf->flags & FT_SF_FLAG_MAXLEN) ? (size_t)sf->maxlen : 1;
	len = ft_strplen(sf->str, &sf->str[maxlen]);
	if (!(sf->flags & FT_SF_FLAG_SKIP))
	{
		str = va_arg(*sf->ap, char*);
		if (!str)
		{
			sf->flags |= FT_SF_QUIT | FT_SF_ERROR;
			return (1);
		}
		ft_strncpy(str, sf->str, len);
	}
	sf->str += len;
	return (1);
}
