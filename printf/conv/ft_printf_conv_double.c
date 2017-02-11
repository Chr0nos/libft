/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:07:35 by snicolet          #+#    #+#             */
/*   Updated: 2017/02/11 10:24:26 by snicolet         ###   ########.fr       */
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
	int		len;

	str = ft_dtoa(*(double*)(unsigned long)&pf->raw_value,
		(unsigned int)((pf->flags & FT_PF_PREC) ? pf->precision : 6));
	if (!str)
	{
		pf->flags |= FT_PF_ERROR | FT_PF_QUIT;
		return ;
	}
	len = (int)ft_strlen(str);
	ft_memcpy(pf->pre_buffer, str, (unsigned int)len);
	pf->slen = len;
	pf->raw_len = len;
	free(str);
}

void				ft_pf_conv_double(t_printf *pf)
{
	ft_printf_append(pf, pf->pre_buffer, (size_t)pf->raw_len);
}
