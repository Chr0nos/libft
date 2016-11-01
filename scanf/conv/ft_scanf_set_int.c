/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:09:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/01 19:39:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scanf_set_int_len(t_scanf *sf)
{
	int			len;

	len = 0;
	while (ft_strany(sf->str[len], "\t\n\v\f\r+-"))
		len++;
	while (ft_isdigit(sf->str[len]))
		len++;
	return (len);
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
	*result = ft_atoi(sf->str);
	if (sf->flags & FT_SF_MOD_HH)
		*result = (int)(char)*result;
	else if (sf->flags & FT_SF_MOD_H)
		*result = (int)(short)*result;
	sf->str += len;
	return (1);
}
