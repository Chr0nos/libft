/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:47:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/09 17:58:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

int		ft_scanf_set_n(t_scanf *sf)
{
	if (sf->flags & FT_SF_FLAG_SKIP)
		return (FT_SF_OK);
	if (sf->flags & FT_SF_MOD_H)
		*(int*)va_arg(*sf->ap, int*) =
			(int)((size_t)sf->str - (size_t)sf->str_origin);
	else
		*(size_t*)va_arg(*sf->ap, size_t *) =
			(size_t)sf->str - (size_t)sf->str_origin;
	return (FT_SF_OK);
}
