/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:15:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/06 14:05:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_scanf.h"

/*
** this function load modifiers then choose wich convertions to use
*/

static inline const char	*ft_scanf_exec(const char *format, t_scanf *sf)
{
	int			p;

	p = FT_SF_CONVCOUNT;
	if (format[0] == '%')
		format++;
	if (!*format)
		return (format);
	format = ft_scanf_loadmods(format, sf);
	while (p--)
		if (*format == g_scanf_set[p].letter)
			return (format + g_scanf_set[p].set(sf));
	return (format);
}

static const char			*ft_scanf_skipword(const char *format, t_scanf *sf)
{
	while ((*sf->str) && (*sf->str != ' '))
		sf->str++;
	return (format);
}

/*
** this function skip some patterns if found in format:
** \\s : will sky any spaces at this place
** \\w : skip the next word in format
** \\S : skip the next \t\v\r\n or spaces at this place
*/

static const char			*ft_scanf_skiper(const char *format, t_scanf *sf)
{
	if (!format[1])
		return (format);
	if (!ft_strncmp(format, "\\s", 2))
	{
		format += 2;
		while (*sf->str == ' ')
			sf->str++;
	}
	else if (!ft_strncmp(format, "\\w", 2))
		format = ft_scanf_skipword(format + 2, sf);
	else if (!ft_strncmp(format, "\\S", 2))
	{
		format += 2;
		while (ft_strany(*sf->str, " \t\v\n\r"))
			sf->str++;
	}
	return (format);
}

static unsigned int			ft_scanf_engine(const char *format, t_scanf *sf)
{
	while ((*format) && (!((sf->flags & FT_SF_QUIT))))
	{
		sf->flags = 0;
		if (*format == '%')
		{
			format = ft_scanf_exec(format, sf);
			if (!(sf->flags & FT_SF_ERROR))
				sf->arg_done++;
		}
		else if (*format == '\\')
			format = ft_scanf_skiper(format, sf);
		else if (*format == *sf->str)
		{
			format++;
			sf->str++;
		}
		else
			return (FT_SF_ERROR);
	}
	if (*format)
		return (FT_SF_ERROR);
	return (0);
}

int							ft_sscanf(const char *s, const char *format, ...)
{
	va_list			ap;
	t_scanf			sf;

	sf.total_len = 0;
	sf.flags = 0;
	sf.ap = &ap;
	sf.str = s;
	sf.precision = 6;
	sf.min_width = 0;
	sf.arg_done = 0;
	va_start(ap, format);
	sf.flags |= ft_scanf_engine(format, &sf);
	va_end(ap);
	return ((sf.flags & FT_SF_ERROR) ? -1 : 0);
}
