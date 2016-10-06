/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:41:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 18:54:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_arg(t_printf *pf, size_t size)
{
	if (pf->flags & FT_PF_MOD_H)
		size = sizeof(short);
	if (pf->flags & FT_PF_MOD_HH)
		size = sizeof(char);
	if (pf->flags & FT_PF_MOD_L)
		size = sizeof(long);
	if (pf->flags & FT_PF_MOD_LL)
		size = sizeof(long long);
	if (pf->flags & FT_PF_MOD_J)
		size = sizeof(intmax_t);
	if (pf->flags & FT_PF_MOD_Z)
		size = sizeof(size_t);
	if (pf->flags & FT_PF_PTR)
		size = sizeof(void*);
	if (size <= 4)
		pf->raw_value = va_arg(*pf->ap, int);
	else
		pf->raw_value = va_arg(*pf->ap, long);
}

void	ft_pf_arg_nbr(t_printf *pf)
{
	if (pf->flags & FT_PF_MOD_J)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, intmax_t);
	else if (pf->flags & FT_PF_MOD_Z)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, size_t);
	else if (pf->flags & FT_PF_MOD_LL)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, long long);
	else if (pf->flags & FT_PF_MOD_L)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, long);
	else if (pf->flags & FT_PF_MOD_H)
		pf->raw_value = (intmax_t)(short)va_arg(*pf->ap, int);
	else if (pf->flags & FT_PF_MOD_HH)
		pf->raw_value = (intmax_t)(char)va_arg(*pf->ap, int);
	else
		pf->raw_value = (intmax_t)va_arg(*pf->ap, int);
}

void	ft_pf_arg_unbr(t_printf *pf)
{
	if (pf->flags & FT_PF_MOD_J)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, uintmax_t);
	else if (pf->flags & FT_PF_MOD_Z)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, ssize_t);
	else if (pf->flags & FT_PF_MOD_LL)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, unsigned long long);
	else if (pf->flags & FT_PF_MOD_L)
		pf->raw_value = (intmax_t)va_arg(*pf->ap, unsigned long);
	else if (pf->flags & FT_PF_MOD_H)
		pf->raw_value = (intmax_t)(unsigned short)va_arg(*pf->ap, unsigned int);
	else if (pf->flags & FT_PF_MOD_HH)
		pf->raw_value = (intmax_t)(unsigned char)va_arg(*pf->ap, unsigned int);
	else
		pf->raw_value = (intmax_t)va_arg(*pf->ap, unsigned int);
}
