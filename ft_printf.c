/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/25 19:07:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int				ft_printf_engine(const char *s, t_printf *pf)
{
	int		len;
	int		pos;

	(void)pf;
	len = 0;
	pos = 0;
	while (*s)
	{
		if ((pos = ft_strchrpos(s, '%')) < 0)
			break ;
		s += pos;
		ft_putendl(s);
	}
	return (len);
}

static void				ft_printf_init(t_printf *pf, va_list *ap)
{
	pf->ap = ap;
	pf->buffer[0] = '\0';
	pf->bpos = 0;
	pf->flags = 0;
	pf->precision = 0;
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
