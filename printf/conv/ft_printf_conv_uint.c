/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 02:03:36 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 19:14:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void					ft_pf_len_uint(t_printf *pf)
{
	int				len;

	len = ft_udigit_len((uintmax_t)pf->raw_value, 10u);
	pf->raw_len = len;
	if ((pf->flags & FT_PF_PREC) && (len < pf->precision))
		len = pf->precision;
	pf->slen = len;
}

void					ft_pf_conv_uint(t_printf *pf)
{
	char				buff[64];
	const uintmax_t		nb = (uintmax_t)pf->raw_value;
	int					len;

	ft_ulltobuff(buff, (unsigned long long)nb, 10, "0123456789");
	len = pf->slen;
	ft_printf_padding(pf, '0', len - pf->raw_len);
	ft_printf_append(pf, buff, (size_t)pf->raw_len);
}
