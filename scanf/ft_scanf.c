/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:15:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/01 15:00:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_scanf.h"

int							ft_scanf_set_int(t_scanf *sf)
{
	int			*result;
	int			len;

	len = 0;
	while (ft_strany(sf->str[len], "\t\n\v\f\r+-"))
		len++;
	while (ft_isdigit(sf->str[len]))
		len++;
	result = (int *)va_arg(*sf->ap, int *);
	*result = ft_atoi(sf->str);
	if (sf->flags & FT_SF_MOD_HH)
		*result = (int)(char)*result;
	else if (sf->flags & FT_SF_MOD_H)
		*result = (int)(short)*result;
	sf->str += len;
	return (1);
}

int							ft_scanf_set_str(t_scanf *sf)
{
	int		len;

	len = (int)ft_strlen(sf->str);
	*va_arg(*sf->ap, char **) = ft_memdup(sf->str, (size_t)len + 1);
	sf->str += len;
	return (1);
}

/*
** this function load modifiers then choose wich convertions to use
*/

static inline const char	*ft_scanf_exec(const char *format, t_scanf *sf)
{
	int			p;

	p = FT_SF_CONVCOUNT;
	ft_printf("dbg2: %s\n", format);
	if (format[0] == '%')
		format++;
	if (!*format)
		return (format);
	ft_scanf_loadmods(format, sf);
	while (p--)
		if (*format == g_scanf_set[p].letter)
			return (format + g_scanf_set[p].set(sf));
	return (format);
}

static int					ft_scanf_engine(const char *format, t_scanf *sf)
{
	while ((*format) && (!((sf->flags & FT_SF_QUIT))))
	{
		sf->flags = 0;
		if (*format == '%')
			format = ft_scanf_exec(format, sf);
		else if (!ft_strncmp(format, "\\s", 2))
		{
			format += 2;
			while (*sf->str == ' ')
				sf->str++;
		}
		else if (*format == *sf->str)
		{
			format++;
			sf->str++;
		}
		else
			return (FT_SF_ERROR);
	}
	return (0);
}

int							ft_sscanf(const char *s, const char *format, ...)
{
	va_list		ap;
	t_scanf		sf;

	sf.total_len = 0;
	sf.flags = 0;
	sf.ap = &ap;
	sf.str = s;
	va_start(ap, format);
	ft_printf("return state: %b\n", ft_scanf_engine(format, &sf));
	va_end(ap);
	return (0);
}
