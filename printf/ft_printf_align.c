/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_align.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:31:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 20:03:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_isaligned_left(t_printf *pf)
{
	return ((!(pf->flags & FT_PF_FLAG_LESS)) &&
		(pf->flags & FT_PF_MINWIDTH));
}

int		ft_printf_isaligned_right(t_printf *pf)
{
	return ((pf->flags & FT_PF_MINWIDTH) &&
		(pf->flags & FT_PF_FLAG_LESS));
}

void	ft_printf_align_left(t_printf *pf, int len)
{
	if (!ft_printf_isaligned_left(pf))
		return ;
	ft_printf_padding(pf, ' ', pf->min_width - len);
}
