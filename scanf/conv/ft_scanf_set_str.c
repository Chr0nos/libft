/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:11:48 by snicolet          #+#    #+#             */
/*   Updated: 2017/02/11 10:25:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** this function is here to ensure the case of given precision AND maxlen
** in this particular case: the precision will be the only used, but if
** no precision is given but a maxlen is, the maxlen will be set as precision
** and the flag FT_SF_FLAG_PREC will be set
*/

static inline void			ft_scanf_fixmaxlen_prec(t_scanf *sf)
{
	if ((sf->flags & FT_SF_FLAG_MAXLEN) && (!(sf->flags & FT_SF_FLAG_PREC)))
	{
		sf->flags |= FT_SF_FLAG_PREC;
		sf->precision = sf->maxlen;
	}
}

int							ft_scanf_set_str(t_scanf *sf)
{
	size_t		len;
	char		*str;

	ft_scanf_fixmaxlen_prec(sf);
	len = (sf->flags & (FT_SF_FLAG_PREC)) ?
		ft_strplen(sf->str, &sf->str[sf->precision]) :
		ft_strlen(sf->str);
	if (!(sf->flags & FT_SF_FLAG_SKIP))
	{
		if (!(str = malloc(sizeof(char) * (len + 1))))
		{
			sf->flags |= FT_SF_ERROR | FT_SF_QUIT;
			return (1);
		}
		ft_memcpy(str, sf->str, len);
		str[len] = '\0';
		*va_arg(*sf->ap, char **) = str;
	}
	sf->str += len;
	return (1);
}
