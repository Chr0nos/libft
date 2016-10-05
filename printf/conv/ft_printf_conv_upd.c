/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_upd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 01:53:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 01:55:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_convert_upd(t_printf *pf)
{
	pf->flags |= FT_PRINTF_MOD_L;
	ft_printf_convert_int(pf);
}
