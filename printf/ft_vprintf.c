/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:12:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/12 16:06:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsnprintf(char *buffer, size_t n, const char *format, va_list ap)
{
	t_printf	pf;
	va_list		vac;

	va_copy(vac, ap);
	ft_printf_init(&pf, &vac);
	pf.flags |= FT_PF_NOWRITE;
	pf.buff_start = buffer;
	pf.space_left = n;
	pf.buffer_maxsize = n;
	ft_printf_engine(format, &pf);
	return ((int)pf.size);
}


int		ft_vprintf(char *buffer, const char *format, va_list ap)
{
	return (ft_vsnprintf(buffer, (unsigned int)-1, format, ap));
}

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_printf	pf;
	va_list		vac;

	va_copy(vac, ap);
	ft_printf_init(&pf, &vac);
	pf.fd = fd;
	ft_printf_engine(format, &pf);
	return ((int)pf.size);
}
