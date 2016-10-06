/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:25:01 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 23:15:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_pt_arg_pc(t_printf *pf)
{
	(void)pf;
}

void					ft_pf_conv_percent(t_printf *pf)
{
	if (pf->flags & FT_PF_FLAG_ZERO)
		ft_printf_padding(pf, '0', pf->slen - pf->raw_len);
	ft_printf_append(pf, "%", 1);
}
