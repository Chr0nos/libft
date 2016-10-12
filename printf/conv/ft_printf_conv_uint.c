/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 02:03:36 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 00:37:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void					ft_pf_len_uint(t_printf *pf)
{
	int				len;

	len = ft_ulltobuff(pf->pre_buffer, (unsigned long long)pf->raw_value, 10,
		"0123456789");
	ft_pf_fixprecision_null(pf, &len);
	pf->raw_len = len;
	if ((pf->flags & FT_PF_PREC) && (len < pf->precision))
		len = pf->precision;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > len))
		len = pf->min_width;
	pf->slen = len;
}

void					ft_pf_conv_uint(t_printf *pf)
{
	ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	ft_printf_append(pf, pf->pre_buffer, (size_t)pf->raw_len);
}
