/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:17:59 by snicolet          #+#    #+#             */
/*   Updated: 2017/03/04 11:15:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
	else if (pf->flags & FT_PF_FLAG_DIESE)
		pf->slen++;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > len))
		pf->slen = pf->min_width;
}

void		ft_pf_conv_bits(t_printf *pf)
{
	uintmax_t			nb;
	int					bit;

	bit = pf->raw_len - 1;
	nb = (uintmax_t)pf->raw_value;
	pf->pre_buffer[bit--] = "01"[nb & 1u];
	while ((nb >>= 1))
		pf->pre_buffer[bit--] = "01"[nb & 1u];
	if (bit >= 0)
		ft_memset(pf->pre_buffer, '0', (unsigned)bit + 1);
	if (pf->flags & FT_PF_FLAG_DIESE)
		pf->slen -= ft_printf_append(pf, "b", 1);
	ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	ft_printf_append(pf, pf->pre_buffer, (size_t)pf->raw_len);
}
