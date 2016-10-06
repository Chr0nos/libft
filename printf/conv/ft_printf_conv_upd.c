/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_upd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 01:53:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 15:37:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_pf_conv_upd(t_printf *pf)
{
	pf->flags |= FT_PRINTF_MOD_L;
	pf->flags &= ~(FT_PRINTF_MOD_H | FT_PRINTF_MOD_HH);
	ft_pf_conv_int(pf);
}
