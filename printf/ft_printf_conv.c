/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:37:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/07 02:44:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** if the type is a pointer the address read will be forced to void*
** if the type is numeric the precison override flag 0
*/

static inline void		ft_printf_flags_override(t_printf *pf,
	const t_printf_convert *conv)
{
	if (conv->isptr)
		pf->flags |= FT_PF_PTR;
	if (conv->isnumeric)
	{
		pf->flags |= FT_PF_NUMERIC;
		if (pf->flags & FT_PF_PREC)
			pf->flags &= ~FT_PF_FLAG_ZERO;
	}
	if (pf->flags & FT_PF_FLAG_LESS)
		pf->flags &= ~FT_PF_FLAG_ZERO;
}

static inline void		ft_printf_conv_postalign(t_printf *pf, const TCO *conv)
{
	if ((ft_printf_isaligned_right(pf)) &&
			(pf->lastlen < pf->min_width))
		ft_printf_padding(pf,
			((conv->isptr) &&
				(pf->flags & FT_PF_FLAG_ZERO)) ? '0' : ' ',
			(int)(pf->min_width - pf->lastlen));
}

static inline void		ft_printf_conv_init(t_printf *pf)
{
	pf->lastlen = 0;
	pf->slen = 0;
	pf->raw_len = 0;
}

static inline void		ft_printd_conv_real(t_printf *pf, const TCO *conv)
{
	ft_printf_flags_override(pf, conv);
	conv->get_arg(pf);
	conv->set_len(pf);
	if (!(pf->flags & FT_PF_FLAG_LESS))
		ft_printf_padding(pf, ' ', pf->min_width - pf->slen);
	conv->convert(pf);
	ft_printf_conv_postalign(pf, conv);
}

/*
** this function apply the convert to the current convert mode,
** if the convert mode is unknow then the char is printed
*/

void					ft_printf_conv(t_printf *pf, const char c)
{
	int						p;
	const t_printf_convert	*conv;

	ft_printf_conv_init(pf);
	p = FT_PF_CONVS;
	while (p--)
	{
		conv = &g_printf_convs[p];
		if ((char)conv->letter == c)
		{
			ft_printd_conv_real(pf, conv);
			return ;
		}
	}
	ft_pf_conv_unknow(pf, c);
}
