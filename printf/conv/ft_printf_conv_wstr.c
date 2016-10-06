/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wstr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:14:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 15:42:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static inline void		ft_printf_conv_wstr_align(t_printf *pf, wchar_t *str)
{
	size_t		slen;

	if (!ft_printf_isaligned_left(pf))
		return ;
	slen = ft_wstrlen(str);
	ft_printf_padding(pf, (pf->flags & FT_PF_FLAG_ZERO) ? '0' : ' ',
		pf->min_field - (int)slen);
}

void					ft_pf_conv_wstr(t_printf *pf)
{
	char				buff[4];
	wchar_t				*str;
	int					len;

	str = (wchar_t*)pf->raw_value;
	if (!str)
	{
		ft_printf_append(pf, "(null)", 6);
		return ;
	}
	ft_printf_conv_wstr_align(pf, str);
	while (*str)
	{
		len = ft_buffwchar(*(str++), buff);
		ft_printf_append(pf, buff, (size_t)len);
	}
}
