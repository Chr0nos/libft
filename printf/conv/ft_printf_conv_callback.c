/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_callback.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:37:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/11 17:56:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** this function will load the core for the custom callback convert mode
** the pointer is retrived by ft_pf_arg_ptr, the convert will be called here
** because the callback function has to set the good lens values for spaces
** alignement
** the callback function MUST be prototyped as: void callback(t_printf *pf)
** the userdata will be given in pf->raw_value
** the call shoudld like somethink like:
** ft_printf("test %k\n", &callback_function, 42);
** lens modifiers are taken in care so if you wish to pass pointers/longs
** you will have to use %lk
** so userdata will be set into pf->raw_value
** the usercallback should write into pf->slen and pf->raw_len
** see ft_printf.h for details
*/

void		ft_pf_len_callback(t_printf *pf)
{
	void	(*callback)(t_printf *);

	callback = (void(*)(t_printf *pf))va_arg(*pf->ap, void*);
	if (!callback)
		return ;
	pf->slen = 0;
	pf->raw_len = 0;
	ft_pf_arg_unbr(pf);
	callback(pf);
}

/*
** the same as previous BUT this one will not provide any value in pf->raw_value
** so the value of pf->raw_value will be the same as "before" this conversion
*/

void		ft_pf_len_upcallback(t_printf *pf)
{
	void	(*callback)(t_printf *);

	if (!(callback = (void(*)(t_printf *pf))va_arg(*pf->ap, void*)))
		return ;
	pf->slen = 0;
	pf->raw_len = 0;
	callback(pf);
}
