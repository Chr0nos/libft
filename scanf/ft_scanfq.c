/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanfq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 01:53:51 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/05 15:29:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** same as ft_sscanf but no modifiers will be allowed, this permit
** a significant gain of speed in the sscanf implementation
*/

int							ft_sscanfq(const char *s, const char *format, ...)
{
	va_list			ap;
	t_scanf			sf;

	sf = (t_scanf){
		.total_len = 0,
		.flags = FT_SF_MOD_NONE,
		.flags_mask = FT_SF_MOD_NONE,
		.str = s,
		.str_origin = s,
		.format = format,
		.precision = 0,
		.min_width = 0,
		.arg_done = 0,
		.maxlen = 0,
		.ap = &ap,
		.padding = 0
	};
	va_start(ap, format);
	sf.flags |= ft_scanf_engine(format, &sf);
	va_end(ap);
	return ((int)sf.arg_done);
}

/*
** this one don't take any modifiers either and don't set any parameter execept
** for the %N conversion (retrive the current format position)
*/

int							ft_sscanfqf(const char *s, const char *format, ...)
{
	va_list			ap;
	t_scanf			sf;

	sf = (t_scanf){
		.total_len = 0,
		.flags = FT_SF_MOD_NONE | FT_SF_FLAG_SKIP,
		.flags_mask = FT_SF_MOD_NONE | FT_SF_FLAG_SKIP,
		.str = s,
		.str_origin = s,
		.format = format,
		.precision = 0,
		.min_width = 0,
		.arg_done = 0,
		.maxlen = 0,
		.ap = &ap,
		.padding = 0
	};
	va_start(ap, format);
	sf.flags |= ft_scanf_engine(format, &sf);
	va_end(ap);
	return ((int)sf.arg_done);
}
