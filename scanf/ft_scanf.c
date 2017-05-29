/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:15:33 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/29 02:08:44 by snicolet         ###   ########.fr       */
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
	if (!(sf->flags & FT_SF_MOD_NONE))
		format = ft_scanf_loadmods(format, sf);
	while (p--)
	{
		sf->format = format;
		if (*format == g_scanf_set[p].letter)
			return (format + g_scanf_set[p].set(sf));
	}
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
** \\n : skip until the next new line
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
	else if (!ft_strncmp(format, "\\n", 2))
	{
		format += 2;
		if ((sf->str = (const char *)ft_strchr((char *)(size_t)sf->str, '\n')))
			sf->str++;
		else
			sf->flags |= FT_SF_QUIT;
	}
	return (format);
}

unsigned int				ft_scanf_engine(const char *format, t_scanf *sf)
{
	while ((*format) && (!((sf->flags & FT_SF_QUIT))))
	{
		sf->flags &= sf->flags_mask;
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

	sf = (t_scanf){
		.total_len = 0,
		.flags = 0,
		.flags_mask = 0,
		.str = s,
		.str_origin = s,
		.format = format,
		.precision = 0,
		.min_width = 0,
		.arg_done = 0,
		.maxlen = 0,
		.ap = &ap,
		.padding = 0
	};
	va_start(ap, format);
	sf.flags |= ft_scanf_engine(format, &sf);
	va_end(ap);
	return ((int)sf.arg_done);
}
