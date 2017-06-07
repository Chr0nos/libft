/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:32:28 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/07 19:51:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_scanf_set_float_len(const char *str)
{
	int		len;

	len = 0;
	if (*str == '-')
		len++;
	while (ft_isdigit(str[len]))
		len++;
	if (str[len] == '.')
	{
		len++;
		while (ft_isdigit(str[len]))
			len++;
	}
	return (len);
}

int				ft_scanf_set_float(t_scanf *sf)
{
	if (!(sf->flags & FT_SF_FLAG_SKIP))
	{
		if (sf->flags & FT_SF_MOD_LL)
			*(long double *)va_arg(*sf->ap, long double *) =
				(long double)ft_atod(sf->str);
		else if (sf->flags & FT_SF_MOD_L)
			*(double*)va_arg(*sf->ap, double *) = ft_atod(sf->str);
		else
			*(float *)va_arg(*sf->ap, float*) = (float)ft_atod(sf->str);
	}
	sf->str += ft_scanf_set_float_len(sf->str);
	return (1);
}
