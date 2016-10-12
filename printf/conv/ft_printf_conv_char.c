/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:05:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 23:47:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_pf_arg_char(t_printf *pf)
{
	if (pf->flags & FT_PF_MOD_L)
		pf->raw_value = (intmax_t)(unsigned int)(va_arg(*pf->ap, unsigned int));
	else
		pf->raw_value = (char)va_arg(*pf->ap, int);
}

void				ft_pf_len_char(t_printf *pf)
{
	pf->slen = 1;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > 1))
		pf->slen = pf->min_width;
	pf->raw_len = 1;
}

void				ft_pf_conv_char(t_printf *pf)
{
	const char		c = (char)pf->raw_value;

	if (pf->flags & FT_PF_FLAG_ZERO)
		ft_printf_padding(pf, '0', pf->slen - 1);
	if (pf->flags & FT_PF_MOD_L)
		ft_pf_conv_wchar(pf);
	else
		ft_printf_append(pf, (const char*)&c, 1);
}
