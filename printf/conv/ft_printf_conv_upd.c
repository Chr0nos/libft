/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_upd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 01:53:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 04:40:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_convert_upd(t_printf *pf)
{
	pf->flags |= FT_PRINTF_MOD_L;
	pf->flags &= ~(FT_PRINTF_MOD_H | FT_PRINTF_MOD_HH);
	ft_printf_convert_int(pf);
}
