/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:23:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 00:28:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void					ft_pf_fixprecision_null(t_printf *pf, int *len)
{
	if ((pf->flags & FT_PF_PREC) && (!(pf->precision | pf->raw_value)))
		*len = 0;
}

void					ft_pf_len_int(t_printf *pf)
{
	int				len;

	len = ft_digit_len(pf->raw_value, 10u);
	ft_pf_fixprecision_null(pf, &len);
	pf->raw_len = len;
	if ((pf->flags & FT_PF_PREC) && (len < pf->precision))
		len = pf->precision;
	if ((pf->flags & (FT_PF_FLAG_SPACE | FT_PF_FLAG_MORE)) ||
			(pf->raw_value < 0))
		len++;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > len))
		len = pf->min_width;
	pf->slen = len;
}

void					ft_pf_conv_int(t_printf *pf)
{
	const intmax_t		nb = pf->raw_value;
	int					len;
	const int			neg = (nb < 0) ? 1 : 0;

	ft_ulltobuff(pf->pre_buffer, (unsigned long long)(nb < 0) ?
		(unsigned long long)-nb : (unsigned long long)nb, 10, "0123456789");
	len = pf->slen;
	if (neg)
		len -= (int)ft_printf_append(pf, "-", 1);
	else if (pf->flags & (FT_PF_FLAG_SPACE | FT_PF_FLAG_MORE))
		len -= (int)ft_printf_append(pf,
			(pf->flags & FT_PF_FLAG_MORE) ? "+" : " ", 1);
	if (!(pf->flags & FT_PF_FLAG_LESS))
		ft_printf_padding(pf, '0', len - pf->raw_len);
	ft_printf_append(pf, pf->pre_buffer, (size_t)pf->raw_len);
}
