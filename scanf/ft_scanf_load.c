/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:59:23 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/29 01:34:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char		*ft_scanf_loadprecision(const char *format, t_scanf *sf)
{
	if (*format != '.')
		return (format);
	format++;
	if (*format == '*')
	{
		sf->precision = va_arg(*sf->ap, int);
		if (sf->precision < 0)
			sf->precision = 0;
		else
			sf->flags |= FT_SF_FLAG_PREC;
		return (format);
	}
	sf->flags |= FT_SF_FLAG_PREC;
	format += ft_atonum(format, &sf->precision);
	return (format);
}

static const char		*ft_scanf_loadmaxlen(const char *format, t_scanf *sf)
{
	const int		len = ft_atonum(format, &sf->precision);

	if ((len) && (sf->precision >= 0))
	{
		format += len;
		sf->flags |= FT_SF_FLAG_MAXLEN;
	}
	return (format);
}

/*
** loads all modifiers into sf->flags then return the address in format
** where the function has stop his job
*/

const char				*ft_scanf_loadmods(const char *format, t_scanf *sf)
{
	const t_scanf_mod	*mod;
	int					p;

	format = ft_scanf_loadmaxlen(format, sf);
	format = ft_scanf_loadprecision(format, sf);
	p = FT_SF_MODS_COUNT;
	while (p--)
	{
		mod = &g_scanf_mods[p];
		if (!ft_strncmp(format, mod->str, mod->len))
		{
			sf->flags |= mod->flag;
			format += mod->len;
			if (!*format)
				return (format);
		}
	}
	return (format);
}
