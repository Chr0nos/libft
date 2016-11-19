/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:47:54 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/20 00:57:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

int		ft_scanf_set_n(t_scanf *sf)
{
	if (sf->flags & FT_SF_MOD_H)
		*(int*)va_arg(*sf->ap, int*) =
			(int)((size_t)sf->str - (size_t)sf->str_origin);
	else
		*(size_t*)va_arg(*sf->ap, size_t *) =
			(size_t)sf->str - (size_t)sf->str_origin;
	return (1);
}
