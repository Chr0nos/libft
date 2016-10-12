/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 00:31:01 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/10 20:20:30 by snicolet         ###   ########.fr       */
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

	p = FT_PF_FLAGSNUM;
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

	p = FT_PF_MODIFIERS;
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
	if (*s != '.')
		return (0);
	if (*(++s) == '*')
	{
		pf->precision = va_arg(*pf->ap, int);
		if (pf->precision < 0)
			pf->precision = 0;
		else
			pf->flags |= FT_PF_PREC;
		return (2);
	}
	pf->flags |= FT_PF_PREC;
	if (ft_isdigit(*s))
		return ((size_t)ft_atonum(s, &pf->precision) + 1);
	else
		pf->precision = 0;
	return (1);
}

static size_t			ft_printf_loadmin_width(t_printf *pf, const char *s)
{
	size_t		seek;

	if ((!ft_strany(*s, "123456789*")) || (pf->flags & FT_PF_PREC))
		return (0);
	pf->flags |= FT_PF_MINWIDTH;
	if (*s == '*')
	{
		pf->min_width = va_arg(*pf->ap, int);
		if (pf->min_width < 0)
		{
			pf->flags |= FT_PF_FLAG_LESS;
			pf->min_width *= -1;
		}
		return (1);
	}
	pf->min_width = ft_atoi(s);
	seek = 0;
	while (ft_isdigit(s[seek]))
		seek++;
	return (seek);
}

size_t					ft_printf_loadall(t_printf *pf, const char *str)
{
	size_t		seek;

	if ((seek = ft_printf_loadmin_width(pf, str)) > 0)
		return (seek);
	if ((seek = (size_t)ft_printf_loadflags(pf, *str)) > 0)
		return (seek);
	if ((seek = ft_printf_loadmodifiers(pf, str)) > 0)
		return (seek);
	if ((seek = ft_printf_loadprecision(pf, str)) > 0)
		return (seek);
	return (0);
}
