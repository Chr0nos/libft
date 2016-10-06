/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 15:37:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

/*
** if the type is a pointer the address read will be forced to void*
** if the type is numeric the precison override flag 0
*/

static void				ft_printf_flags_override(t_printf *pf,
	const t_printf_convert *conv)
{
	if (conv->isptr)
		pf->flags |= FT_PRINTF_PTR;
	if (conv->isnumeric)
	{
		pf->flags |= FT_PRINTF_NUMERIC;
		if (pf->flags & FT_PRINTF_PREC)
			pf->flags &= ~FT_PRINTF_FLAG_ZERO;
	}
}

/*
** this function apply the convert to the current convert mode,
** if the convert mode is unknow then the char is printed
*/

static void				ft_printf_conv(t_printf *pf, const char c)
{
	int						p;
	const t_printf_convert	*conv;

	pf->lastlen = 0;
	p = FT_PRINTF_CONVS;
	while (p--)
	{
		conv = &g_printf_convs[p];
		if ((char)conv->letter == c)
		{
			ft_printf_flags_override(pf, conv);
			ft_printf_arg(pf, conv->size);
			conv->convert(pf);
			if ((ft_printf_isaligned_right(pf)) &&
					(pf->lastlen < pf->min_field))
				ft_printf_padding(pf,
					((conv->isnumeric) &&
						(pf->flags & FT_PRINTF_FLAG_ZERO)) ? '0' : ' ',
					(int)(pf->min_field - pf->lastlen));
			return ;
		}
	}
	ft_pf_conv_nknow(pf, c);
}

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

int						ft_printf_fd(int fd, const char *str, ...)
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
		pf.total_len += pf.size;
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
		pf.total_len += pf.size;
	}
	return ((int)pf.total_len);
}
