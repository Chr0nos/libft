/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/28 21:05:36 by snicolet         ###   ########.fr       */
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
	pf->buffer[0] = '\0';
	pf->size = 0;
	pf->space_left = FT_PRINTF_BSIZE;
}

static void				ft_printf_append(t_printf *pf, const char *data,
	size_t len)
{
	ssize_t		rsize;

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
		pf->size = FT_PRINTF_BSIZE;
		ft_printf_flush(pf);
		data += len;
	}
	ft_memcpy(pf->buff_start, data, len);
	pf->total_len += len;
	pf->size += len;
	pf->buff_start += len;
}

void					ft_printf_convert_int(t_printf *pf)
{
	char			buff[13];

	ft_printf_append(pf, buff,
		(size_t)ft_itobuff(buff, va_arg(*pf->ap, int), 10, "0123456789") + 1);
}

void					ft_printf_convert_str(t_printf *pf)
{
	const char	*str = va_arg(*pf->ap, char *);

	ft_printf_append(pf, str, ft_strlen(str));
}

// test de format %#.8d%

static void				ft_printf_exec(const char *str, int len,
	t_printf *pf)
{
	ft_printf_append(pf, str, (size_t)len);
}

static int				ft_printf_engine(const char *s, t_printf *pf)
{
	int		pos;

	pos = 0;
	while (*s)
	{
		pf->flags = 0;
		pos = ft_strchrpos(s, '%');
		if (pos < 0)
			pos = (int)ft_strlen(s);
		if (!pos)
			break ;
		write(pf->fd, "[", 1);
		write(pf->fd, s, (size_t)pos);
		write(pf->fd, "]", 1);
		ft_printf_exec(s, pos, pf);
		s += pos + 1;
	}
	return (pos);
}

static void				ft_printf_init(t_printf *pf, va_list *ap)
{
	pf->ap = ap;
	pf->buffer[0] = '\0';
	pf->flags = 0;
	pf->precision = 0;
	pf->buff_start = pf->buffer;
	pf->size = 0;
	pf->total_len = 0;
	pf->fd = 1;
}

int						ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;
	t_printf	pf;

	ft_printf_init(&pf, &ap);
	va_start(ap, str);
	ret = ft_printf_engine(str, &pf);
	va_end(ap);
	write(1, pf.buffer, pf.size);
	return (ret);
}
