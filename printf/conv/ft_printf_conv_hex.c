/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:58:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 18:07:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void			ft_printf_convert_hex(t_printf *pf)
{
	char			buff[24];
	int				len;
	const uintmax_t	nb = ft_printf_conv_uint_getnb(pf);

	if ((pf->flags & FT_PRINTF_FLAG_DIESE) && (nb != 0))
		ft_printf_append(pf, "0x", 2);
	len = ft_ulltobuff(buff, (unsigned long long)nb, 16, "0123456789abcdef");
	if (ft_printf_isaligned_left(pf))
		ft_printf_padding(pf, (pf->flags & FT_PRINTF_FLAG_ZERO) ? '0' : ' ',
		pf->min_field - len);
	if ((pf->flags & FT_PRINTF_PREC) && (len > pf->precision))
		len = pf->precision;
	ft_printf_append(pf, buff, (size_t)len);
}

void			ft_printf_convert_uphex(t_printf *pf)
{
	char				buff[24];
	int					len;
	const uintmax_t		nb = ft_printf_conv_uint_getnb(pf);

	if ((pf->flags & FT_PRINTF_FLAG_DIESE) && (nb != 0))
		ft_printf_append(pf, "0X", 2);
	len = ft_ulltobuff(buff, (unsigned long long)nb, 16, "0123456789ABCDEF");
	if (ft_printf_isaligned_left(pf))
		ft_printf_padding(pf, (pf->flags & FT_PRINTF_FLAG_ZERO) ? '0' : ' ',
		pf->min_field - len);
	if ((pf->flags & FT_PRINTF_PREC) && (len > pf->precision))
		len = pf->precision;
	ft_printf_append(pf, buff, (size_t)len);
}
