/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:58:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 18:37:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void inline	ft_printf_conv_hex(t_printf *pf, const uintmax_t nb,
	const char *map)
{
	char		buff[24];
	int			len;

	len = ft_ulltobuff(buff, (unsigned long long)nb, 16, map);
	if (ft_printf_isaligned_left(pf))
		ft_printf_padding(pf, (pf->flags & FT_PRINTF_FLAG_ZERO) ? '0' : ' ',
		pf->min_field - len);
	if ((pf->flags & FT_PRINTF_PREC) && (len > pf->precision))
		len = pf->precision;
	ft_printf_append(pf, buff, (size_t)len);
}

void				ft_printf_convert_hex(t_printf *pf)
{
	const uintmax_t	nb = ft_printf_conv_uint_getnb(pf);

	if ((pf->flags & FT_PRINTF_FLAG_DIESE) && (nb != 0))
		ft_printf_append(pf, "0x", 2);
	ft_printf_conv_hex(pf, nb, "0123456789abcdef");
}

void				ft_printf_convert_uphex(t_printf *pf)
{
	const uintmax_t		nb = ft_printf_conv_uint_getnb(pf);

	if ((pf->flags & FT_PRINTF_FLAG_DIESE) && (nb != 0))
		ft_printf_append(pf, "0X", 2);
	ft_printf_conv_hex(pf, nb, "0123456789ABCDEF");
}
