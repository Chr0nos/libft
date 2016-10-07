/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:17:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/07 15:45:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pf_len_bits(t_printf *pf)
{
	int		len;

	if (pf->flags & FT_PF_MOD_Z)
		len = sizeof(intmax_t);
	else if (pf->flags & FT_PF_MOD_J)
		len = sizeof(size_t);
	else if (pf->flags & FT_PF_MOD_L)
		len = sizeof(long);
	else if (pf->flags & FT_PF_MOD_LL)
		len = sizeof(long long);
	else if (pf->flags & FT_PF_MOD_H)
		len = sizeof(short);
	else if (pf->flags & FT_PF_MOD_HH)
		len = sizeof(char);
	else
		len = sizeof(int);
	pf->raw_len = len * 8;
	pf->slen = pf->raw_len;
	if ((pf->flags & FT_PF_PREC) && (len < pf->precision))
		pf->slen = pf->precision;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > len))
		pf->slen = pf->min_width;
	if (pf->flags & FT_PF_FLAG_DIESE)
		pf->slen++;
}

void		ft_pf_conv_bits(t_printf *pf)
{
	char				buff[64];
	const uintmax_t		nb = (uintmax_t)pf->raw_value;
	const int			bits = pf->raw_len;
	int					p;

	p = 0;
	while (p < bits)
	{
		buff[p] = (nb & (1u << (bits - p))) ? '1' : '0';
		p++;
	}
	if (pf->flags & FT_PF_FLAG_DIESE)
		ft_printf_append(pf, "b", 1);
	ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	ft_printf_append(pf, buff, (size_t)pf->slen);
}
