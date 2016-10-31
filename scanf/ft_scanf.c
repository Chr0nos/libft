/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:15:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/31 21:14:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_scanf.h"

int							ft_scanf_set_int(t_scanf *sf)
{
	int			len;

	len = 0;
	while (ft_isdigit(sf->str[len]))
		len++;
	*(int *)va_arg(*sf->ap, int *) = ft_atoi(sf->str);
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

static inline const char	*ft_scanf_exec(const char *format, t_scanf *sf)
{
	int			p;

	p = FT_SF_CONVERTS;
	ft_printf("dbg2: %s\n", format);
	if (format[0] == '%')
		format++;
	if (!*format)
		return (format);
	while (p--)
		if (*format == g_scanf_set[p].letter)
			return (format + g_scanf_set[p].set(sf));
	return (format);
}

/*
** this function jump between each % checking for validity of format
*/

static int					ft_scanf_engine(const char *format,
	t_scanf *sf)
{
	const char		*c;
	const char		*sep = "%";
	int				len;

	ft_putendl("dbg0");
	while (((c = ft_strforf(format, sep, &len)) != NULL) &&
		(!(sf->flags & (FT_SF_QUIT | FT_SF_ERROR))))
	{
		ft_printf("dbg1: [%d] %s\n", len, c);
		if ((len) && (ft_strncmp(sf->str, format, (size_t)len)))
			return (FT_SF_QUIT | FT_SF_ERROR);
		format = ft_scanf_exec(c, sf);
		if (!*sf->str)
			sf->flags |= FT_SF_QUIT;
		ft_printf("dbg3: %hhd\n", *format);
	}
	if (*format)
	{
		ft_printf("rest: %s --- %s\n", sf->str, format);
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
