/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:38:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/19 00:27:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_scanf_set_hexlen(const char *str, const char *map)
{
	const char	*start = str;

	while ((*str) && (ft_strany(*str, map)))
		str++;
	return ((size_t)str - (size_t)start);
}

int					ft_scanf_set_hex(t_scanf *sf)
{
	const size_t		len = ft_scanf_set_hexlen(sf->str, "0123456789abcdef");
	unsigned long		val;

	if (!len)
	{
		sf->flags |= FT_SF_ERROR;
		return (1);
	}
	if (!(sf->flags & FT_SF_FLAG_SKIP))
	{
		val = ft_basetoul(sf->str, "0123456789abcdef");
		if (sf->flags & FT_SF_MOD_H)
			*(unsigned short*)va_arg(*sf->ap, unsigned short *) =
				(unsigned short)val;
		else if (sf->flags & FT_SF_MOD_HH)
			*(unsigned char *)va_arg(*sf->ap, unsigned char *) =
				(unsigned char)val;
		else if (sf->flags & (FT_SF_MOD_L | FT_SF_MOD_LL))
			*(unsigned long *)va_arg(*sf->ap, unsigned long*) = val;
		else
			*(unsigned int *)va_arg(*sf->ap, unsigned int*) = (unsigned int)val;
	}
	sf->str += len;
	return (1);
}
