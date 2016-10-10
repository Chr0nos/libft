/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_kernel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:37:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/10 16:18:00 by snicolet         ###   ########.fr       */
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
** the call shoudld like somethink like:
** ft_printf("test %k\n", &kernel_function, &userdata);
** so userdata will be set into pf->raw_value
** the userkernel should write into pf->slen and pf->raw_len
** see ft_printf.h for details
*/

void		ft_pf_len_kernel(t_printf *pf)
{
	void	(*kernel)(t_printf *);

	kernel = (void(*)(t_printf *pf))va_arg(*pf->ap, void*);
	if (!kernel)
		return ;
	pf->slen = 0;
	pf->raw_len = 0;
	pf->raw_value = (intmax_t)va_arg(*pf->ap, void*);
	kernel(pf);
}
