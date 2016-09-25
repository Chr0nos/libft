/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/26 00:12:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

// test de format %#.8d%

static int				ft_printf_poopinator(const char *str, int len,
	t_printf *pf)
{
	const size_t	pos = (size_t)pf->buff_start - (size_t)pf->buffer;
	const size_t	space_left = FT_PRINTF_BSIZE - pos;

	if (FT_PRINTF_BSIZE <= len)
		write(1, str, len);
	else if (len > space_left)
	{
		write(1, pf->buffer, pos);
		pf->buff_start = pf->buffer;
		pf->buffer[0] = '\0';
	}
}

static int				ft_printf_engine(const char *s, t_printf *pf)
{
	int		pos;

	(void)pf;
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
