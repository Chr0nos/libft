/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:29:35 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/09 17:57:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_number_len(const char *str)
{
	const char		*origin = str;

	if ((!str) || (!*str) || (!ft_strchr("0123456789", *str)))
		return (0);
	while (ft_isdigit(*str))
		str++;
	return ((unsigned int)((size_t)str - (size_t)origin));
}

int						ft_scanf_set_uint(t_scanf *sf)
{
	unsigned long long		value;
	const unsigned int		len = ft_number_len(sf->str);

	if (!len)
		return (FT_SF_ERROR);
	value = ft_basetoul(sf->str, "0123456789");
	sf->str += len;
	if (sf->flags & FT_SF_FLAG_SKIP)
		return (1);
	if (sf->flags & FT_SF_MOD_LL)
		*va_arg(*sf->ap, unsigned long long *) = value;
	else if (sf->flags & FT_SF_MOD_L)
		*va_arg(*sf->ap, size_t *) = (size_t)value;
	else if (sf->flags & FT_SF_MOD_H)
		*va_arg(*sf->ap, unsigned short *) = (unsigned short)value;
	else if (sf->flags & FT_SF_MOD_HH)
		*va_arg(*sf->ap, unsigned char *) = (unsigned char)value;
	else
		*va_arg(*sf->ap, unsigned int *) = (unsigned int)value;
	return (FT_SF_OK);
}
