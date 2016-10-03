/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/03 16:27:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void					ft_printf_flush(t_printf *pf)
{
	const ssize_t	size = write(pf->fd, pf->buffer, pf->size);

	if (size > 0)
		pf->total_len += (size_t)size;
	pf->buff_start = pf->buffer;
	pf->size = 0;
	pf->space_left = FT_PRINTF_BSIZE;
}

void					ft_printf_append(t_printf *pf, const char *data,
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

void					ft_printf_padding(t_printf *pf, const char c, int n)
{
	if ((size_t)n <= pf->space_left)
	{
		ft_memset(pf->buff_start, (int)c, (size_t)n);
		pf->buff_start += n;
		pf->size += (size_t)n;
		return ;
	}
	while (n--)
		ft_printf_append(pf, &c, 1);
}

/*
** (flag / modifier / precision) loaders functions
*/

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
	while ((p--) && (ft_strncmp(m[p].modifier, str, m[p].len)))
		;
	if (p < 0)
		return (0);
	pf->flags |= g_printf_modifiers[p].flag;
	pf->flags &= g_printf_modifiers[p].mask;
	return (g_printf_modifiers[p].len + 1);
}

static size_t			ft_printf_loadprecision(t_printf *pf, const char *s)
{
	size_t		p;

	if (*s != '.')
		return (0);
	if ((!s[1]) || (!ft_isdigit(s[1])))
	{
		pf->precision = 0;
		pf->flags |= FT_PRINTF_PREC;
		return (1);
	}
	if (*(++s) == '*')
	{
		pf->precision = va_arg(*pf->ap, int);
		pf->flags |= FT_PRINTF_PREC;
		return (1);
	}
	pf->precision = ft_atoi(s);
	if (pf->precision < 0)
		pf->precision = 0;
	else
		pf->flags |= FT_PRINTF_PREC;
	p = 1;
	while (ft_isdigit(s[p]))
		p++;
	return (p + 1);
}

static size_t			ft_printf_loadmin_field(t_printf *pf, const char *s)
{
	size_t		seek;

	if ((!ft_isdigit(*s)) || (pf->flags & FT_PRINTF_PREC))
		return (0);
	pf->flags |= FT_PRINTF_MINFIELD;
	if (*s == '*')
	{
		pf->min_field = va_arg(*pf->ap, int);
		return (1);
	}
	pf->min_field = ft_atoi(s);
	seek = 0;
	while (ft_isdigit(s[seek]))
		seek++;
	return (seek);
}

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
			g_printf_convs[p].convert(pf);
			if ((pf->flags & FT_PRINTF_MINFIELD) &&
					(!(pf->flags & FT_PRINTF_FLAG_LESS)) &&
					(pf->lastlen < pf->min_field))
				ft_printf_padding(pf, ' ', (int)(pf->min_field - pf->lastlen));
			return ;
		}
	}
	ft_printf_append(pf, &c, 1);
}

static inline size_t	ft_printf_loadall(t_printf *pf, const char *str)
{
	size_t		seek;

	if ((seek = ft_printf_loadmin_field(pf, str)) > 0)
		return (seek);
	if ((seek = (size_t)ft_printf_loadflags(pf, *str)) > 0)
		return (seek);
	if ((seek = ft_printf_loadmodifiers(pf, str)) > 0)
		return (seek);
	if ((seek = ft_printf_loadprecision(pf, str)) > 0)
		return (seek);
	return (0);
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
