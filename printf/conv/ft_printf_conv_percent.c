/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:25:01 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 19:34:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_pt_arg_pc(t_printf *pf)
{
	(void)pf;
}

void					ft_pf_conv_percent(t_printf *pf)
{
	ft_printf_append(pf, "%", 1);
}
