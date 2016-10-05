/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 05:13:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

/*
** this function apply the convert to the current convert mode,
** if the convert mode is unknow then the char is printed
*/

static void				ft_printf_conv(t_printf *pf, const char c)
{
	int		p;

	pf->lastlen = 0;
	p = FT_PRINTF_CONVS;
	while (p--)
	{
		if ((char)g_printf_convs[p].letter == c)
		{
			ft_printf_arg(pf, g_printf_convs[p].size);
			g_printf_convs[p].convert(pf);
			if ((pf->flags & FT_PRINTF_MINFIELD) &&
					((pf->flags & FT_PRINTF_FLAG_LESS)) &&
					(pf->lastlen < pf->min_field))
				ft_printf_padding(pf, ' ', (int)(pf->min_field - pf->lastlen));
			return ;
		}
	}
	ft_printf_append(pf, &c, 1);
}

/*
** called on each sub chain delimited by %
*/

static const char		*ft_printf_exec(const char *str, t_printf *pf)
{
	size_t			seek;

	if (*str == '%')
	{
		ft_printf_convert_percent(pf);
		return (str + 1);
	}
	seek = 0;
	while ((*str) && (!ft_strany(*str, FT_PRINTF_CONVERTS)))
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

static void				ft_printf_init(t_printf *pf, va_list *ap)
{
	pf->ap = ap;
	pf->flags = 0;
	pf->precision = 0;
	pf->buff_start = pf->buffer;
	pf->size = 0;
	pf->total_len = 0;
	pf->fd = 1;
	pf->min_field = 0;
	pf->space_left = FT_PRINTF_BSIZE;
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
		pf.total_len += pf.size;
	}
	return ((int)pf.total_len);
}
