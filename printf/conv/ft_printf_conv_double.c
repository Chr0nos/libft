/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:07:35 by snicolet          #+#    #+#             */
/*   Updated: 2018/10/20 15:17:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void				ft_pf_arg_double(t_printf *pf)
{
	const double	x = va_arg(*pf->ap, double);

	pf->raw_value = (intmax_t)(*(const unsigned long *)&x);
}

void				ft_pf_len_double(t_printf *pf)
{
	char	*str;

	str = ft_dtoa(*(double*)(unsigned long)&pf->raw_value,
		(unsigned int)((pf->flags & FT_PF_PREC) ? pf->precision : 6));
	if (!str)
	{
		pf->flags |= FT_PF_ERROR | FT_PF_QUIT;
		return ;
	}
	pf->slen = (int)ft_strlen(str);
	ft_memcpy(pf->pre_buffer, str, (unsigned int)pf->slen);
	pf->raw_len = pf->slen;
	free(str);
}

void				ft_pf_conv_double(t_printf *pf)
{
	ft_printf_padding(pf, (pf->flags & FT_PF_FLAG_ZERO) ? '0' : ' ',
		pf->min_width - pf->raw_len);
	ft_printf_append(pf, pf->pre_buffer, (size_t)pf->raw_len);
}
