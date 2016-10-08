/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 20:30:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

/*
** called on each sub chain delimited by %
*/

static const char		*ft_printf_exec(const char *str, t_printf *pf)
{
	size_t			seek;

	if (*str == '%')
	{
		ft_pf_conv_percent(pf);
		return (str + 1);
	}
	seek = 0;
	while ((*str) && (!ft_strany(*str, FT_PF_CONVERTS)))
	{
		if (!(seek = ft_printf_loadall(pf, str)))
			break ;
		str += seek;
	}
	if (*str)
	{
		ft_printf_conv(pf, *str);
		return (str + 1);
	}
	return (str);
}

static void				ft_printf_engine(const char *fstr, t_printf *pf)
{
	const char		*c;
	const char		*sep = "%";
	int				len;

	while ((c = ft_strforf(fstr, sep, &len)) != NULL)
	{
		pf->flags = 0;
		ft_printf_append(pf, fstr, (size_t)len);
		fstr = ft_printf_exec(c + 1, pf);
	}
	ft_printf_append(pf, fstr, (size_t)len);
}

int						ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;
	t_printf	pf;

	va_start(ap, str);
	ft_printf_init(&pf, &ap);
	pf.fd = fd;
	ft_printf_engine(str, &pf);
	va_end(ap);
	if (pf.size)
	{
		write(pf.fd, pf.buffer, pf.size);
		return (int)((pf.total_len + pf.size));
	}
	return ((int)pf.total_len);
}

/*
** todo: add sprintf / asprintf / dprintf
*/

int						ft_printf(const char *str, ...)
{
	va_list		ap;
	t_printf	pf;

	va_start(ap, str);
	ft_printf_init(&pf, &ap);
	ft_printf_engine(str, &pf);
	va_end(ap);
	if (pf.size)
	{
		write(pf.fd, pf.buffer, pf.size);
		return ((int)(pf.total_len + pf.size));
	}
	return ((int)pf.total_len);
}
