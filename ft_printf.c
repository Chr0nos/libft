/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/26 21:24:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int				ft_printf_convert_int(t_printf *pf)
{
	char			buff[13];
	int				len;
	const int		max = (pf->flags & FT_PRINTF_PREC) ? pf->precision : 13;

	len = ft_itobuff(buff, va_arg(*pf->ap, int), 10, "0123456789");
	if (len > max)
		len = max;
	memcpy(pf->buff_start, buff, len + 1);
	return (len);
}

// test de format %#.8d%

static int				ft_printf_poopinator(const char *str, int len,
	t_printf *pf)
{
	const size_t	pos = (size_t)pf->buff_start - (size_t)pf->buffer;
	const size_t	space_left = FT_PRINTF_BSIZE - pos;

	//si la string a faire est plus grande que la taille du buffer on la write
	//en une seule fois
	if (FT_PRINTF_BSIZE <= len)
		write(1, str, (size_t)len);
	//si le buffer n a pas assez de place pour acceuilir la chaine, on le flush
	else if ((size_t)len > space_left)
	{
		write(1, pf->buffer, pos);
		pf->buff_start = pf->buffer;
		pf->buffer[0] = '\0';
	}
	pf->total_len += (size_t)len;
	return (0);
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
		write(1, "[", 1);
		write(1, s, (size_t)pos);
		write(1, "]", 1);
		ft_printf_poopinator(s, pos, pf);
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
	pf->total_len = 0;
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
	return (ret);
}
