/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 15:04:59 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 16:05:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_vsprintf(const char *s, va_list *ap)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if ((*s == '%') && (++s))
		{
			if ((*s == 's') && (++s))
				ft_putstr(va_arg(*ap, char *));
			else if ((*s == 'd') && (++s))
				ft_putnbr(va_arg(*ap, int));
			else if ((*s == 'p') && (++s))
				ft_putptr(va_arg(*ap, void *));
			else if ((*s == '%') && (++s))
				ft_putchar('%');
		}
		else
		{
			len = ft_strsublen(s, '%');
			write(1, s, len);
			s += len;
		}
	}
	return ((int)len);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, str);
	ret = ft_vsprintf(str, &ap);
	va_end(ap);
	return (ret);
}
