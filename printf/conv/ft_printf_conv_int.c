/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:23:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 22:09:20 by snicolet         ###   ########.fr       */
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

void					ft_printf_convert_int(t_printf *pf)
{
	char			buff[13];
	const int		nb = (int)pf->raw_value;
	int				len;
	int				miss;

	len = ft_itobuff(buff, nb, 10, "0123456789");
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
