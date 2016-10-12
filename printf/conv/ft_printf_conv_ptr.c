/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:22:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/10 20:10:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void				ft_pf_arg_ptr(t_printf *pf)
{
	pf->raw_value = (intmax_t)va_arg(*pf->ap, void*);
}

void				ft_pf_conv_ptr(t_printf *pf)
{
	pf->flags |= FT_PF_MOD_L | FT_PF_FLAG_DIESE | FT_PF_PTR;
	ft_pf_conv_hex(pf);
}
