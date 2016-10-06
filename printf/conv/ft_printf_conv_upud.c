/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_upud.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 02:08:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 16:11:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pf_conv_upud(t_printf *pf)
{
	pf->flags |= FT_PF_MOD_L;
	pf->flags &= ~(FT_PF_MOD_H | FT_PF_MOD_HH);
	ft_pf_conv_uint(pf);
}
