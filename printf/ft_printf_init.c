/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:54:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/12 15:31:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_printf_init(t_printf *pf, va_list *ap)
{
	pf->ap = ap;
	pf->flags = 0;
	pf->precision = 0;
	pf->buff_start = pf->buffer;
	pf->size = 0;
	pf->total_len = 0;
	pf->fd = 1;
	pf->min_width = 0;
	pf->space_left = FT_PF_BSIZE;
	pf->buffer_maxsize = FT_PF_BSIZE;
}
