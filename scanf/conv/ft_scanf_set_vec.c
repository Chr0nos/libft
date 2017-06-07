/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:15:42 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/07 20:19:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** vector function loader modifiers:
** hh : char
** h : int
** nothing: float
** l : double
** ll : will be threat as l
** ---
** the number of items per vector is determined by the precision attribute ex:
** ft_sscanf(line, "%4v", &vector);
** will set a vec4
*/

static int	ft_scanf_set_vec_len(const t_scanf *sf)
{
	if (sf->flags & (FT_SF_MOD_HH | FT_SF_MOD_H))
		return (ft_scanf_set_int_len(sf));
	return (ft_scanf_set_float_len(sf->str));
}

int			ft_scanf_set_vec(t_scanf *sf)
{
	void	*ptr;
	int		vec_n;

	ptr = va_arg(*sf->ap, void*);
	vec_n = 0;
	while ((vec_n < sf->precision) && (ft_strchr("0123456789+-.", *sf->str)))
	{
		if (sf->flags & FT_SF_FLAG_SKIP)
			;
		else if (sf->flags & FT_SF_MOD_L)
			((double*)ptr)[vec_n] = ft_atod(sf->str);
		else if (sf->flags & FT_SF_MOD_HH)
			((char*)ptr)[vec_n] = (char)ft_atoi(sf->str);
		else if (sf->flags & FT_SF_MOD_H)
			((int*)ptr)[vec_n] = ft_atoi(sf->str);
		else
			((float*)ptr)[vec_n] = (float)ft_atod(sf->str);
		sf->str += ft_scanf_set_vec_len(sf);
		vec_n++;
		if (vec_n != sf->precision)
			while ((*sf->str) && (ft_strchr(" \t\n\r\v", *sf->str)))
				sf->str++;
	}
	return (1);
}
