/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:41:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 04:34:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_arg(t_printf *pf, size_t size)
{
	if (pf->flags & FT_PRINTF_MOD_H)
		size = sizeof(short);
	if (pf->flags & FT_PRINTF_MOD_HH)
		size = sizeof(char);
	if (pf->flags & FT_PRINTF_MOD_L)
		size = sizeof(long);
	if (pf->flags & FT_PRINTF_MOD_LL)
		size = sizeof(long long);
	if (pf->flags & FT_PRINTF_MOD_J)
		size = sizeof(intmax_t);
	if (pf->flags & FT_PRINTF_MOD_Z)
		size = sizeof(size_t);
	if (size <= 4)
		pf->raw_value = va_arg(*pf->ap, int);
	else
		pf->raw_value = va_arg(*pf->ap, long);
}
