/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:48:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/07 14:35:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_pf_len_octal(t_printf *pf)
{
	int				len;

	len = ft_udigit_len((uintmax_t)pf->raw_value, 8u);
	ft_pf_fixprecision_null(pf, &len);
	pf->raw_len = len;
	if ((pf->flags & FT_PF_PREC) && (len < pf->precision))
		len = pf->precision;
	else if ((pf->flags & FT_PF_FLAG_DIESE) && ((pf->raw_value) || (!len)))
		len++;
	if ((pf->flags & FT_PF_FLAG_ZERO) && (pf->min_width > len))
		len = pf->min_width;
	pf->slen = len;
}

void			ft_pf_conv_octal(t_printf *pf)
{
	char				buff[64];
	const uintmax_t		nb = (uintmax_t)pf->raw_value;

	ft_ulltobuff(buff, (unsigned long long)nb, 8, "012345678");
	if (!(pf->flags & FT_PF_FLAG_LESS))
		ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	else if ((pf->flags & FT_PF_FLAG_DIESE) && (pf->raw_value))
		ft_printf_append(pf, "0", 1);
	ft_printf_append(pf, buff, (size_t)pf->raw_len);
}
