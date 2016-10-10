/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 23:59:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/11 01:39:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** the buffered version of ft_printf
** return the len wrote in buffer, cannot be supperior to N
** if N is lower than the data to convert, the result will be truncated
** the string in buffer will NOT be \0 terminated
** a valid use could be:
** write(1, buff, ft_snprintf(buff, 512, "%s\n", "test string"));
** (this will result with a similar result of ft_printf in 512 chars limit)
*/

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

/*
** here the size is set to intmax, this function should not be used,
** use ft_snprintf instead
*/

int			ft_sprintf(char *buffer, char *str, ...)
{
	va_list				ap;
	t_printf			pf;
	const size_t		n = (unsigned int)-1;

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
