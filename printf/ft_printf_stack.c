/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:58:06 by snicolet          #+#    #+#             */
/*   Updated: 2019/05/10 12:56:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
/*
** this function's purpose is to be called INSIDE a previous call of printf,
** like ft_printf, ft_snprintf etc, in a normal case this is called inside a
** callback function of printf (%k or %K)
** the big idea here is to prevent a maximum of "write" syscalls, and prevent
** too many stack usage (each ft_printf call causes a FT_PF_BSIZE buf in the
** stack, this is not acceptable for many calls inside a callback function)
** does not send NULL for pf (SEGFAULT)
*/

int							ft_printf_stack(t_printf *pf,
	const char *format, ...)
{
	va_list				ap;
	va_list				*origin_ap;

	origin_ap = pf->ap;
	va_start(ap, format);
	pf->ap = &ap;
	ft_printf_engine(format, pf);
	va_end(ap);
	pf->ap = origin_ap;
	return ((int)pf->size);
}
