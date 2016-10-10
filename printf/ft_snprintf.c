/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 23:59:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/11 01:28:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_snprintf(char *buffer, size_t n, char *str, ...)
{
	va_list		ap;
	t_printf	pf;

	va_start(ap, str);
	ft_printf_init(&pf, &ap);
	pf.flags |= FT_PF_NOWRITE;
	pf.buff_start = buffer;
	pf.space_left = n;
	pf.buffer_maxsize = n;
	ft_printf_engine(str, &pf);
	va_end(ap);
	return ((int)pf.size);
}
