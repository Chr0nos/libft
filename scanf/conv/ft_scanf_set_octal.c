/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_octal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:50:08 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/12 16:24:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_scanf_set_octallen(const char *str)
{
	const char	*start = str;

	while ((*str) && (*str >= '0') && (*str <= '7'))
		str++;
	return ((size_t)str - (size_t)start);
}

int					ft_scanf_set_octal(t_scanf *sf)
{
	const size_t		len = ft_scanf_set_octallen(sf->str);
	unsigned long		v;

	if (!len)
	{
		sf->flags |= FT_SF_ERROR;
		return (1);
	}
	if (!(sf->flags & FT_SF_FLAG_SKIP))
	{
		v = ft_basetoul(sf->str, "01234567");
		if (sf->flags & FT_SF_MOD_H)
			*(unsigned int *)va_arg(*sf->ap, unsigned int *) = (unsigned int)v;
		else if (sf->flags & FT_SF_MOD_HH)
			*(unsigned char *)va_arg(*sf->ap, unsigned char *) =
				(unsigned char)v;
		else
			*(unsigned long *)va_arg(*sf->ap, unsigned long *) = v;
	}
	sf->str += len;
	return (1);
}
