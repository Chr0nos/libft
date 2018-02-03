/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:20:46 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/03 00:22:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_scanf_set_char(t_scanf *sf)
{
	size_t			len;
	size_t			maxlen;
	char			*str;

	str = va_arg(*sf->ap, char*);
	if (!str)
	{
		sf->flags |= FT_SF_QUIT | FT_SF_ERROR;
		return (1);
	}
	maxlen = (sf->flags & FT_SF_FLAG_MAXLEN) ? (size_t)sf->maxlen : 1;
	len = ft_strplen(sf->str, &sf->str[maxlen]);
	ft_strncpy(str, sf->str, len);
	sf->str += len;
	return (1);
}
