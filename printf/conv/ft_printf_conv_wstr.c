/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wstr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:14:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 23:01:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int				ft_pf_len_wstr_cap(const wchar_t *str, int max)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = 0;
	while (*str)
	{
		tmp += ft_wcharlen(*str);
		if (tmp > max)
			return (len);
		len = tmp;
		str++;
	}
	return (len);
}

void					ft_pf_len_wstr(t_printf *pf)
{
	const wchar_t	*str = (const wchar_t*)pf->raw_value;
	int				len;

	if (!str)
	{
		pf->raw_len = ((pf->flags & FT_PF_PREC) && (pf->precision < 6)) ?
			pf->precision : 6;
		pf->slen = pf->raw_len;
		return ;
	}
	len = (pf->flags & FT_PF_PREC) ? ft_pf_len_wstr_cap(str, pf->precision) :
		(int)ft_wstrlen(str);
	pf->raw_len = len;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > pf->raw_len))
		pf->slen = pf->min_width;
	else
		pf->slen = pf->raw_len;
}

void					ft_pf_conv_wstr(t_printf *pf)
{
	char				buff[4];
	wchar_t				*str;
	int					len;

	str = (wchar_t*)pf->raw_value;
	if (pf->flags & FT_PF_FLAG_ZERO)
		ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	if (!str)
	{
		ft_printf_append(pf, "(null)", (size_t)pf->raw_len);
		return ;
	}
	len = pf->raw_len;
	while (len)
		len -= ft_printf_append(pf, buff, (size_t)ft_buffwchar(*(str++), buff));
}
