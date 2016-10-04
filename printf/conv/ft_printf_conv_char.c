/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:05:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 18:21:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_printf_convert_char(t_printf *pf)
{
	char		c;

	c = (char)pf->raw_value;
	if (pf->flags & FT_PRINTF_PREC)
		ft_printf_padding(pf, ' ', pf->precision - 1);
	ft_printf_append(pf, (char*)&c, 1);
}
