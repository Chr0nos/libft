/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:24:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 02:58:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void					ft_pf_len_str(t_printf *pf)
{
	const char	*str = (const char*)pf->raw_value;

	if (!str)
		pf->raw_len = ((pf->flags & FT_PF_PREC) && (pf->precision < 6)) ?
			pf->precision : 6;
	else if (pf->flags & FT_PF_MOD_L)
		ft_pf_len_wstr(pf);
	else if (pf->flags & FT_PF_PREC)
		pf->raw_len = (int)ft_strplen(str, &str[pf->precision]);
	else
		pf->raw_len = (int)ft_strlen(str);
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > pf->raw_len))
		pf->slen = pf->min_width;
	else
		pf->slen = pf->raw_len;
}

void					ft_pf_conv_str(t_printf *pf)
{
	if (pf->flags & FT_PF_MOD_L)
	{
		ft_pf_conv_wstr(pf);
		return ;
	}
	if (pf->flags & FT_PF_FLAG_ZERO)
		ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	if (!pf->raw_value)
	{
		ft_printf_append(pf, "(null)", (size_t)pf->raw_len);
		return ;
	}
	ft_printf_append(pf, (const char*)pf->raw_value, (unsigned)pf->raw_len);
}
