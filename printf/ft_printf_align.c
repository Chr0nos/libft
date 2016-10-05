/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_align.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:31:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 11:41:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_isaligned_left(t_printf *pf)
{
	return ((!(pf->flags & FT_PRINTF_FLAG_LESS)) &&
		(pf->flags & FT_PRINTF_MINFIELD));
}

int		ft_printf_isaligned_right(t_printf *pf)
{
	return ((pf->flags & FT_PRINTF_MINFIELD) &&
		(pf->flags & FT_PRINTF_FLAG_LESS));
}
