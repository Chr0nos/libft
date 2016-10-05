/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 00:31:01 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 19:58:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** (flag / modifier / precision) loaders functions
*/

static int				ft_printf_loadflags(t_printf *pf, const char c)
{
	int		p;

	p = FT_PRINTF_FLAGSNUM;
	while ((p--) && ((char)g_printf_cfg[p].letter != c))
		;
	if (p < 0)
		return (0);
	if (pf->flags & g_printf_cfg[p].refuse)
		return (1);
	pf->flags |= g_printf_cfg[p].flag;
	pf->flags &= g_printf_cfg[p].mask;
	return (1);
}

static size_t			ft_printf_loadmodifiers(t_printf *pf, const char *str)
{
	int						p;
	const t_printf_modif	*m = (const t_printf_modif*)&g_printf_modifiers;

	p = FT_PRINTF_MODIFIERS;
	while ((p--) && (ft_strncmp(m[p].modifier, str, m[p].len)))
		;
	if (p < 0)
		return (0);
	pf->flags |= g_printf_modifiers[p].flag;
	pf->flags &= g_printf_modifiers[p].mask;
	return (g_printf_modifiers[p].len);
}

static size_t			ft_printf_loadprecision(t_printf *pf, const char *s)
{
	size_t		p;

	if (*s != '.')
		return (0);
	//pf->flags &= ~FT_PRINTF_FLAG_ZERO;
	if (*(s++) == '*')
	{
		pf->precision = va_arg(*pf->ap, int);
		pf->flags |= FT_PRINTF_PREC;
		return (1);
	}
	if ((!*s) || (!ft_isdigit(*s)))
	{
		pf->precision = 0;
		pf->flags |= FT_PRINTF_PREC;
		return (1);
	}
	pf->precision = ft_atoi(s);
	if (pf->precision < 0)
		pf->precision = 0;
	else
		pf->flags |= FT_PRINTF_PREC;
	p = 1;
	while (ft_isdigit(s[p]))
		p++;
	return (p + 1);
}

static size_t			ft_printf_loadmin_field(t_printf *pf, const char *s)
{
	size_t		seek;

	if ((!ft_strany(*s, "123456789*")) || (pf->flags & FT_PRINTF_PREC))
		return (0);
	pf->flags |= FT_PRINTF_MINFIELD;
	if (*s == '*')
	{
		pf->min_field = va_arg(*pf->ap, int);
		if (pf->min_field < 0)
		{
			pf->flags |= FT_PRINTF_FLAG_LESS;
			pf->min_field *= -1;
		}
		return (1);
	}
	pf->min_field = ft_atoi(s);
	seek = 0;
	while (ft_isdigit(s[seek]))
		seek++;
	return (seek);
}

size_t					ft_printf_loadall(t_printf *pf, const char *str)
{
	size_t		seek;

	if ((seek = ft_printf_loadmin_field(pf, str)) > 0)
		return (seek);
	if ((seek = (size_t)ft_printf_loadflags(pf, *str)) > 0)
		return (seek);
	if ((seek = ft_printf_loadmodifiers(pf, str)) > 0)
		return (seek);
	if ((seek = ft_printf_loadprecision(pf, str)) > 0)
		return (seek);
	return (0);
}
