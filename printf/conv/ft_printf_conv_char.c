/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:05:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 05:19:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_printf_convert_char(t_printf *pf)
{
	const char		c = (char)pf->raw_value;

	if (!(pf->flags & FT_PRINTF_FLAG_LESS))
		ft_printf_padding(pf, ' ', pf->min_field - 1);
	if (pf->flags & FT_PRINTF_MOD_L)
		ft_printf_convert_wchar(pf);
	else
		ft_printf_append(pf, (const char*)&c, 1);
}
