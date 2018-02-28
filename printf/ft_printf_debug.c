/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:05:24 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 20:24:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_debug(const t_printf *pf)
{
	ft_printf("%s%s%p%s%b%s%d%s%d%s%d%s%d%s%lu%s%lu%s%lu%s",
		"----- FT_PRINTF_DEBUG -----\n",
		"va list ptr: ", pf->ap,
		"\nflags: ", pf->flags,
		"\nprecision: ", pf->precision,
		"\nfd: ", pf->fd,
		"\nmin_width: ", pf->min_width,
		"\nraw len: ", pf->raw_len,
		"\nsize: ", pf->size,
		"\nspace left: ", pf->space_left,
		"\nbuffer max size: ", pf->buffer_maxsize,
		"\n-------------------------\n");
}
