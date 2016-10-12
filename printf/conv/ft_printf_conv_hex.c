/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:58:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 00:55:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void				ft_pf_len_hex(t_printf *pf)
{
	int				len;

	len = ft_udigit_len((uintmax_t)pf->raw_value, 16u);
	ft_pf_fixprecision_null(pf, &len);
	pf->raw_len = len;
	if ((pf->flags & FT_PF_PREC) && (len < pf->precision))
		len = pf->precision;
	if ((pf->flags & (FT_PF_FLAG_DIESE)) && (pf->raw_value))
		len += 2;
	else if (pf->flags & FT_PF_PTR)
		len += 2;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > len))
		len = pf->min_width;
	pf->slen = len;
}

void				ft_pf_conv_hex(t_printf *pf)
{
	int					len;

	ft_ulltobuff(pf->pre_buffer, (unsigned long long)pf->raw_value, 16,
		"0123456789abcdef");
	len = pf->slen;
	if ((pf->flags & FT_PF_FLAG_DIESE) &&
			((pf->raw_value) || (pf->flags & FT_PF_PTR)))
		len -= ft_printf_append(pf, "0x", 2);
	ft_printf_padding(pf, '0', len - pf->raw_len);
	ft_printf_append(pf, pf->pre_buffer, (size_t)pf->raw_len);
}

void				ft_pf_conv_uphex(t_printf *pf)
{
	int					len;

	ft_ulltobuff(pf->pre_buffer, (unsigned long long)pf->raw_value, 16,
		"0123456789ABCDEF");
	len = pf->slen;
	if ((pf->flags & FT_PF_FLAG_DIESE) && (pf->raw_value))
		len -= ft_printf_append(pf, "0X", 2);
	ft_printf_padding(pf, '0', len - pf->raw_len);
	ft_printf_append(pf, pf->pre_buffer, (size_t)pf->raw_len);
}
