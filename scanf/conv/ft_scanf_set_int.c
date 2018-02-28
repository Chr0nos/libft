/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:09:11 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 22:43:25 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_scanf_set_int_len(const t_scanf *sf)
{
	unsigned int	len;

	len = 0;
	if ((sf->str[len] == '+') || (sf->str[len] == '-'))
		len++;
	while (ft_isdigit(sf->str[len]))
		len++;
	return (len);
}

static int		ft_scanf_set_bigint(t_scanf *sf, void *ptr)
{
	intmax_t		nb;

	nb = 0;
	if ((*sf->str == '+') || (*sf->str == '-'))
		sf->str++;
	while (ft_isdigit(*sf->str))
		nb = (nb * 10) + (*(sf->str++) - '0');
	if (sf->flags & FT_SF_MOD_J)
		*(intmax_t*)ptr = nb;
	else
		*(ssize_t*)ptr = (ssize_t)nb;
	return (1);
}

int				ft_scanf_set_int(t_scanf *sf)
{
	const unsigned int len = ft_scanf_set_int_len(sf);

	if (sf->flags & FT_SF_FLAG_SKIP)
	{
		sf->str += len;
		return (1);
	}
	if ((!ft_isdigit(*sf->str)) && (!ft_strchr("+-", *sf->str)))
	{
		sf->flags |= FT_SF_QUIT | FT_SF_ERROR;
		return (1);
	}
	if (sf->flags & FT_SF_MOD_ANYI)
		return (ft_scanf_set_bigint(sf, va_arg(*sf->ap, void*)));
	else if (sf->flags & FT_SF_MOD_HH)
		*va_arg(*sf->ap, char *) = (char)ft_atoi(sf->str);
	else if (sf->flags & FT_SF_MOD_H)
		*va_arg(*sf->ap, short *) = (short)ft_atoi(sf->str);
	else
		*va_arg(*sf->ap, int *) = ft_atoi(sf->str);
	sf->str += len;
	return (1);
}
