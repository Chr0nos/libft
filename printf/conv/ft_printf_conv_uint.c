/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 02:03:36 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 03:36:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void				ft_printf_conv_uint_minfield(t_printf *pf, int len)
{
	const int		missing = pf->min_field - len;

	if (missing > 0)
		ft_printf_padding(pf, ' ', missing);
}

uintmax_t				ft_printf_conv_uint_getnb(t_printf *pf)
{
	if (pf->flags & FT_PRINTF_MOD_J)
		return ((uintmax_t)pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_Z)
		return ((uintmax_t)(size_t)pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_HH)
		return ((uintmax_t)(unsigned char)pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_H)
		return (uintmax_t)(unsigned short)pf->raw_value;
	else if (pf->flags & FT_PRINTF_MOD_LL)
		return ((uintmax_t)(unsigned long long)pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_L)
		return ((uintmax_t)(unsigned long)pf->raw_value);
	return ((unsigned int)pf->raw_value);
}

void					ft_printf_convert_uint(t_printf *pf)
{
	char				buff[64];
	const uintmax_t		nb = ft_printf_conv_uint_getnb(pf);
	int					len;
	int					miss;

	len = ft_ulltobuff(buff, (unsigned long long)nb, 10, "0123456789");
	if (pf->flags & FT_PRINTF_PREC)
	{
		miss = pf->precision - len;
		if (miss > 0)
			ft_printf_padding(pf, '0', miss);
	}
	if (pf->flags & FT_PRINTF_FLAG_LESS)
		ft_printf_conv_uint_minfield(pf, len +
			((pf->flags & FT_PRINTF_FLAG_MORE) ? 1 : 0));
	if (pf->flags & FT_PRINTF_FLAG_MORE)
		ft_printf_append(pf, "+", 1);
	if (pf->flags & FT_PRINTF_FLAG_SPACE)
		ft_printf_append(pf, " ", 1);
	ft_printf_append(pf, buff, (size_t)len);
}
