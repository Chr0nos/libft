/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:24:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 16:10:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
	size_t			len;

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
	if (pf->flags & FT_PF_PREC)
	{
		len = 0;
		while ((*str) && (len < (size_t)pf->precision))
			len++;
	}
	else
		len = ft_strlen(str);
	if (ft_printf_isaligned_left(pf))
		ft_printf_padding(pf, (pf->flags & FT_PF_FLAG_ZERO) ? '0' : ' ',
		pf->min_field - (int)len);
	ft_printf_append(pf, str, len);
}
