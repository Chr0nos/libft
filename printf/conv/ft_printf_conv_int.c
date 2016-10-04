/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:23:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 00:10:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void				ft_printf_conv_int_minfield(t_printf *pf, int len)
{
	const int		missing = pf->min_field - len;

	if (missing > 0)
		ft_printf_padding(pf, ' ', missing);
}

static intmax_t			ft_printf_conv_int_getnb(t_printf *pf)
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
	int					miss;

	len = ft_imaxtobuff(buff, nb, 10, "0123456789");
	if (pf->flags & FT_PRINTF_PREC)
	{
		if (nb < 0)
			ft_printf_append(pf, "-", 1);
		miss = pf->precision - len;
		if (miss > 0)
			ft_printf_padding(pf, '0', miss);
	}
	if (pf->flags & FT_PRINTF_FLAG_LESS)
		ft_printf_conv_int_minfield(pf, len +
			(((nb >= 0) && (pf->flags & FT_PRINTF_FLAG_MORE)) ? 1 : 0));
	if ((pf->flags & FT_PRINTF_FLAG_MORE) && (nb >= 0))
		ft_printf_append(pf, "+", 1);
	ft_printf_append(pf, buff, (size_t)len);
}
