/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_unknow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:30:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 17:32:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pf_conv_unknow(t_printf *pf, char c)
{
	if (ft_printf_isaligned_left(pf))
		ft_printf_padding(pf, ' ', pf->min_width - 1);
	ft_printf_append(pf, &c, 1);
	if ((ft_printf_isaligned_right(pf)) &&
			(pf->lastlen < pf->min_width))
		ft_printf_padding(pf, ' ', (int)(pf->min_width - pf->lastlen));
}
