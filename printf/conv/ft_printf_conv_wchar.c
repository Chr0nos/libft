/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:59:08 by snicolet          #+#    #+#             */
/*   Updated: 2017/03/04 11:14:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void				ft_pf_arg_wchar(t_printf *pf)
{
	pf->raw_value = va_arg(*pf->ap, wchar_t);
}

static inline void	ft_pf_conv_wchar_forcechar(t_printf *pf)
{
	const char		c = (char)pf->raw_value;

	if (pf->flags & FT_PF_FLAG_ZERO)
		ft_printf_padding(pf, '0', pf->slen - 1);
	ft_printf_append(pf, (const char *)&c, 1);
}

void				ft_pf_conv_wchar(t_printf *pf)
{
	wchar_t			nb;
	int				len;

	if (pf->flags & FT_PF_MOD_HH)
		nb = ((wchar_t)(unsigned short)pf->raw_value);
	else
		nb = (wchar_t)pf->raw_value;
	if (!nb)
		ft_printf_append(pf, "\0", 1);
	else if (nb <= 127)
		ft_pf_conv_wchar_forcechar(pf);
	else
	{
		len = ft_buffwchar(nb, pf->pre_buffer);
		if ((pf->flags & FT_PF_PREC) && (len > pf->precision))
			len = pf->precision;
		ft_printf_append(pf, pf->pre_buffer, (size_t)len);
	}
}
