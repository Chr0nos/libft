/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_unknow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:30:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/10 20:08:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pf_conv_unknow(t_printf *pf, char c)
{
	if (!(pf->flags & FT_PF_FLAG_LESS))
		ft_printf_padding(pf, (pf->flags & FT_PF_FLAG_ZERO) ? '0' : ' ',
		pf->min_width - 1);
	ft_printf_append(pf, &c, 1);
	if ((pf->flags & FT_PF_MINWIDTH) && (pf->flags & FT_PF_FLAG_LESS))
		ft_printf_padding(pf, ' ', pf->min_width - 1);
}
