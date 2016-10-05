/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:24:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 03:12:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void				ft_printf_conv_str_null(t_printf *pf)
{
	int		len;
	int		miss;

	len = 6;
	if (pf->flags & FT_PRINTF_PREC)
	{
		miss = pf->precision - 6;
		if (miss > 0)
			len -= miss;
		if (len < 0)
			len = 0;
	}
	ft_printf_append(pf, "(null)", (size_t)len);
}

void					ft_printf_convert_str(t_printf *pf)
{
	const char		*str = (char*)pf->raw_value;
	size_t			len;

	if (pf->flags & FT_PRINTF_MOD_L)
	{
		ft_printf_convert_wstr(pf);
		return ;
	}
	if (!str)
	{
		ft_printf_conv_str_null(pf);
		return ;
	}
	if (pf->flags & FT_PRINTF_PREC)
	{
		len = 0;
		while ((*str) && (len < (size_t)pf->precision))
			len++;
	}
	else
		len = ft_strlen(str);
	ft_printf_append(pf, str, len);
}
