/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:59:08 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 04:55:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_printf_convert_wchar(t_printf *pf)
{
	char			buff[4];
	wchar_t			nb;
	int				len;

	if (pf->flags & FT_PRINTF_MOD_HH)
		nb = ((wchar_t)(unsigned short)pf->raw_value);
	else
		nb = (wchar_t)pf->raw_value;
	if (!nb)
		ft_printf_append(pf, "\0", 1);
	else if (nb <= 127)
		ft_printf_convert_char(pf);
	else
	{
		len = ft_buffwchar(nb, buff);
		if ((pf->flags & FT_PRINTF_PREC) && (len > pf->precision))
			len = pf->precision;
		ft_printf_append(pf, buff, (size_t)len);
	}
}
