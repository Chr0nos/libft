/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_upud.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 02:08:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 04:41:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_convert_upud(t_printf *pf)
{
	pf->flags |= FT_PRINTF_MOD_L;
	pf->flags &= ~(FT_PRINTF_MOD_H | FT_PRINTF_MOD_HH);
	ft_printf_convert_uint(pf);
}
