/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:24:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 22:36:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void					ft_pf_len_str(t_printf *pf)
{
	const char	*str = (const char*)pf->raw_value;
	int			len;

	if (!str)
		pf->raw_len = ((pf->flags & FT_PF_PREC) && (pf->precision < 6)) ?
			pf->precision : 6;
	else if (pf->flags & FT_PF_MOD_L)
		ft_pf_len_wstr(pf);
	else if (pf->flags & FT_PF_PREC)
	{
		len = 0;
		while ((*(str++)) && (len < pf->precision))
			len++;
		pf->raw_len = len;
	}
	else
		pf->raw_len = (int)ft_strlen(str);
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > pf->raw_len))
		pf->slen = pf->min_width;
	else
		pf->slen = pf->raw_len;
}

static void				ft_printf_conv_str_null(t_printf *pf)
{
	int		len;
	int		miss;

	len = 6;
	if (pf->flags & FT_PF_PREC)
	{
		miss = pf->precision - 6;
		if (miss > 0)
			len -= miss;
		if (len < 0)
			len = 0;
	}
	ft_printf_append(pf, "(null)", (size_t)len);
}

void					ft_pf_conv_str(t_printf *pf)
{
	const char		*str = (char*)pf->raw_value;

	if (pf->flags & FT_PF_MOD_L)
	{
		ft_pf_conv_wstr(pf);
		return ;
	}
	if (!str)
	{
		ft_printf_conv_str_null(pf);
		return ;
	}
	if (pf->flags & FT_PF_FLAG_ZERO)
		ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	ft_printf_append(pf, str, (unsigned)pf->raw_len);
}
