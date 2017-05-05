/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 23:59:11 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/06 01:21:47 by snicolet         ###   ########.fr       */
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

int			ft_snprintf(char *buffer, size_t n, char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vsnprintf(buffer, n, format, ap);
	va_end(ap);
	return (ret);
}

/*
** here the size is set to intmax, this function should not be used,
** use ft_snprintf instead
*/

int			ft_sprintf(char *buffer, char *format, ...)
{
	va_list				ap;
	t_printf			pf;

	pf.size = 0;
	va_start(ap, format);
	ft_vsnprintf(buffer, (unsigned int)-1, format, ap);
	va_end(ap);
	return ((int)pf.size);
}
