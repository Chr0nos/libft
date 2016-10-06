/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_align.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:31:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 17:32:32 by snicolet         ###   ########.fr       */
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

void	ft_printf_zeroes(t_printf *pf)
{
	(void)pf;
}

void	ft_printf_padding_len(t_printf *pf, int len)
{
	char	c;

	if (pf->flags & FT_PF_NUMERIC)
		c = (pf->flags & FT_PF_FLAG_ZERO) ? '0' : ' ';
	else
		c = ' ';
	ft_printf_padding(pf, c, pf->min_width - len);
}
