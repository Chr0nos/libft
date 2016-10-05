/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:23:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 17:52:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void				ft_printf_conv_int_minfield(t_printf *pf, int len)
{
	ft_printf_padding(pf,
		(pf->flags & FT_PRINTF_FLAG_ZERO) ? '0' : ' ', pf->min_field - len);
}

intmax_t				ft_printf_conv_int_getnb(t_printf *pf)
{
	if (pf->flags & FT_PRINTF_MOD_J)
		return (pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_Z)
		return ((intmax_t)(size_t)pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_HH)
		return ((intmax_t)(char)pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_H)
		return (intmax_t)(short)pf->raw_value;
	else if (pf->flags & FT_PRINTF_MOD_LL)
		return ((intmax_t)(long long int)pf->raw_value);
	else if (pf->flags & FT_PRINTF_MOD_L)
		return ((intmax_t)(long int)pf->raw_value);
	return ((int)pf->raw_value);
}

void					ft_printf_convert_int(t_printf *pf)
{
	char				buff[64];
	const intmax_t		nb = ft_printf_conv_int_getnb(pf);
	int					len;
	const int			neg = (nb < 0) ? 1 : 0;

	len = ft_ulltobuff(buff, (unsigned long long)(nb < 0) ?
		(unsigned long long)-nb : (unsigned long long)nb, 10, "0123456789");
	if ((neg) && (pf->flags & FT_PRINTF_FLAG_ZERO))
		ft_printf_append(pf, "-", 1);
	if (ft_printf_isaligned_left(pf))
		ft_printf_conv_int_minfield(pf, len +
			(((nb >= 0) && (pf->flags & FT_PRINTF_FLAG_MORE)) ? 1 : 0) +
			((neg) ? 1 : 0));
	if (pf->flags & FT_PRINTF_PREC)
		ft_printf_padding(pf, '0', pf->precision - len);
	if ((pf->flags & FT_PRINTF_FLAG_MORE) && (!neg))
		ft_printf_append(pf, "+", 1);
	if ((pf->flags & FT_PRINTF_FLAG_SPACE) && (!neg))
		ft_printf_append(pf, " ", 1);
	if ((neg) && (!(pf->flags & FT_PRINTF_FLAG_ZERO)))
		ft_printf_append(pf, "-", 1);
	ft_printf_append(pf, buff, (size_t)len);
}
