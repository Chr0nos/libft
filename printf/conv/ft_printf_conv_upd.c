/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_upd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 01:53:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 15:42:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_pf_conv_upd(t_printf *pf)
{
	pf->flags |= FT_PF_MOD_L;
	pf->flags &= ~(FT_PF_MOD_H | FT_PF_MOD_HH);
	ft_pf_conv_int(pf);
}
