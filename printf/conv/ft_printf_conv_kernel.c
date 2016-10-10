/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_kernel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:37:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/10 15:49:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** this function will load the core for the custom kernel convert mode
** the pointer is retrived by ft_pf_arg_ptr, the convert will be called here
** because the kernel function has to set the good lens values for spaces
** alignement
** the kernel function MUST be prototyped as: void kernel(t_printf *pf)
** the userdata will be given in pf->raw_value
*/

void		ft_pf_len_kernel(t_printf *pf)
{
	void	(*kernel)(t_printf *f);

	kernel = (void(*)(t_printf *pf))va_arg(*pf->ap, void*);
	if (!kernel)
		return ;
	pf->slen = 0;
	pf->raw_len = 0;
	ft_pf_arg_ptr(pf);
	kernel(pf);
}
