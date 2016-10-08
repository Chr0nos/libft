/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:47:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/08 18:54:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_len_n(t_printf *pf)
{
	pf->min_width = 0;
	pf->precision = 0;
}

void	ft_pf_conv_n(t_printf *pf)
{
	int		*ptr;

	if (!(ptr = (int*)pf->raw_value))
		return ;
	*ptr = (int)(pf->total_len + pf->size);
}
