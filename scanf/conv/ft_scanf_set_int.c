/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:09:11 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/07 20:13:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_scanf_set_int_len(const t_scanf *sf)
{
	int			len;

	len = 0;
	while (ft_strany(sf->str[len], "\t\n\v\f\r+-"))
		len++;
	while (ft_isdigit(sf->str[len]))
		len++;
	return (len);
}

static int	ft_scanf_set_bigint(t_scanf *sf, void *ptr)
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

int			ft_scanf_set_int(t_scanf *sf)
{
	int			*result;
	const int	len = ft_scanf_set_int_len(sf);

	if (sf->flags & FT_SF_FLAG_SKIP)
	{
		sf->str += len;
		return (1);
	}
	result = (int *)va_arg(*sf->ap, int *);
	if (sf->flags & FT_SF_MOD_ANYI)
		return (ft_scanf_set_bigint(sf, (void*)(size_t)result));
	*result = ft_atoi(sf->str);
	if (sf->flags & FT_SF_MOD_HH)
		*result = (int)(char)*result;
	else if (sf->flags & FT_SF_MOD_H)
		*result = (int)(short)*result;
	sf->str += len;
	return (1);
}
