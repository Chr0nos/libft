/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/29 21:45:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static void				ft_printf_flush(t_printf *pf)
{
	const ssize_t	size = write(pf->fd, pf->buffer, pf->size);

	if (size > 0)
		pf->total_len += (size_t)size;
	pf->buff_start = pf->buffer;
	pf->size = 0;
	pf->space_left = FT_PRINTF_BSIZE;
}

static void				ft_printf_append(t_printf *pf, const char *data,
	size_t len)
{
	ssize_t		rsize;

	if (!len)
		return ;
	if (len > FT_PRINTF_BSIZE)
	{
		ft_printf_flush(pf);
		rsize = write(pf->fd, data, len);
		if (rsize > 0)
			pf->total_len += (size_t)rsize;
		return ;
	}
	else if (len > pf->space_left)
	{
		ft_memcpy(pf->buff_start, data, pf->space_left);
		len -= pf->space_left;
		data += pf->space_left;
		pf->size = FT_PRINTF_BSIZE;
		ft_printf_flush(pf);
	}
	ft_memcpy(pf->buff_start, data, len);
	pf->size += len;
	pf->buff_start += len;
	pf->space_left -= len;
}

void					ft_printf_convert_int(t_printf *pf)
{
	char			buff[13];
	const int		nb = va_arg(*(pf->ap), int);

	if ((nb < 0) && (pf->flags & FT_PRINTF_FLAG_MORE))
	ft_printf_append(pf, "+", 1);
	ft_printf_append(pf, buff,
		(size_t)ft_itobuff(buff, nb, 10, "0123456789"));
}

void					ft_printf_convert_str(t_printf *pf)
{
	const char	*str = va_arg(*(pf->ap), char *);

	ft_printf_append(pf, str, ft_strlen(str));
}

static int				ft_printf_loadflags(t_printf *pf, const char c)
{
	int		p;

	p = FT_PRINTF_FLAGSNUM;
	while ((p--) && ((char)g_printf_cfg[p].letter != c))
		;
	if (p < 0)
		return (0);
	pf->flags |= g_printf_cfg[p].flag;
	pf->flags &= g_printf_cfg[p].mask;
	return (1);
}

static size_t			ft_printf_loadmodifiers(t_printf *pf, const char *str)
{
	int						p;
	const t_printf_modif	*m = (const t_printf_modif*)&g_printf_modifiers;

	p = FT_PRINTF_MODIFIERS;
	while ((p--) && (!ft_strncmp(m[p].modifier, str, m[p].len)))
		;
	if (p < 0)
		return (0);
	pf->flags |= g_printf_modifiers[p].flag;
	pf->flags &= g_printf_modifiers[p].mask;
	return (g_printf_modifiers[p].len);
}

static void				ft_printf_conv(t_printf *pf, const char c)
{
	int		p;

	p = FT_PRINTF_CONVS;
	while (p--)
	{
		if ((char)g_printf_convs[p].letter == c)
		{
			g_printf_convs[p].convert(pf);
			return ;
		}
	}
}

/*
** called on each sub chain delimited by %
*/

static void				ft_printf_exec(const char *str, int len,
	t_printf *pf)
{
	size_t		seek;

	pf->flags = 0;
	while (!ft_strany(*str, FT_PRINTF_CONVERTS))
	{
		if ((!ft_printf_loadflags(pf, *str)) &&
			(seek = ft_printf_loadmodifiers(pf, str) > 1))
		{
			str += seek - 1;
			len -= (int)seek;
		}
		str++;
		len--;
	}
	if (*str)
		ft_printf_conv(pf, *(str++));
}

//ft_printf_append(pf, "][", 2);

static void				ft_printf_engine(const char *s, t_printf *pf)
{
	char		*oldpos;
	const char	*sep = "%";
	int			len;

	oldpos = s;
	while ((len = ft_strforf(&s, sep)) >= 0)
	{
		if (*s)
			ft_printf_exec(oldpos, len, pf);
		oldpos = s;
	}
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
	pf->space_left = FT_PRINTF_BSIZE;
}

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
