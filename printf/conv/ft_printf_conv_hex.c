/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:58:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 19:46:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void				ft_pf_len_hex(t_printf *pf)
{
	int				len;

	len = ft_udigit_len((uintmax_t)pf->raw_value, 16u);
	pf->raw_len = len;
	if ((pf->flags & FT_PF_PREC) && (len < pf->precision))
		len = pf->precision;
	if ((pf->flags & FT_PF_FLAG_DIESE) &&
		((pf->raw_value) || (pf->flags & FT_PF_PTR)))
		len += 2;
	pf->slen = len;
}

void				ft_pf_conv_hex(t_printf *pf)
{
	char				buff[64];
	const uintmax_t		nb = (uintmax_t)pf->raw_value;
	int					len;

	ft_ulltobuff(buff, (unsigned long long)nb, 16, "0123456789abcdef");
	len = pf->slen;
	if ((pf->flags & FT_PF_FLAG_DIESE) && ((nb) || (pf->flags & FT_PF_PTR)))
		len -= ft_printf_append(pf, "0x", 2);
	ft_printf_padding(pf, '0', len - pf->raw_len);
	ft_printf_append(pf, buff, (size_t)pf->raw_len);
}

void				ft_pf_conv_uphex(t_printf *pf)
{
	char				buff[64];
	const uintmax_t		nb = (uintmax_t)pf->raw_value;
	int					len;

	ft_ulltobuff(buff, (unsigned long long)nb, 16, "0123456789ABCDEF");
	len = pf->slen;
	if ((pf->flags & FT_PF_FLAG_DIESE) && (nb))
		len -= ft_printf_append(pf, "0X", 2);
	ft_printf_padding(pf, '0', len - pf->raw_len);
	ft_printf_append(pf, buff, (size_t)pf->raw_len);
}
