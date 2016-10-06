/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:05:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 16:02:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_pf_conv_char(t_printf *pf)
{
	const char		c = (char)pf->raw_value;

	if (ft_printf_isaligned_left(pf))
		ft_printf_padding(pf, (pf->flags & FT_PF_FLAG_ZERO) ? '0' : ' ',
		pf->min_field - 1);
	if (pf->flags & FT_PF_MOD_L)
		ft_pf_conv_wchar(pf);
	else
		ft_printf_append(pf, (const char*)&c, 1);
}
