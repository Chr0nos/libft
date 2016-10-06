/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:22:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int			ft_pf_conv_ptr_padding(t_printf *pf, void *ptr)
{
	int		len;

	if (!ptr)
	{
		len = 3;
		if ((pf->flags & FT_PRINTF_PREC) && (pf->precision < 2))
			len = 2;
		if ((ft_printf_isaligned_left(pf)) &&
				(!(pf->flags & FT_PRINTF_FLAG_ZERO)))
			ft_printf_padding_len(pf, len);
		ft_printf_append(pf, "0x0", (unsigned)len);
		if (pf->flags & FT_PRINTF_PREC)
			ft_printf_padding(pf, '0', pf->precision - 1);
		return (1);
	}
	return (0);
}

void				ft_pf_conv_ptr(t_printf *pf)
{
	void	*ptr;

	ptr = (void*)pf->raw_value;
	if (ft_pf_conv_ptr_padding(pf, ptr))
		return ;
	pf->flags |= FT_PRINTF_MOD_L | FT_PRINTF_FLAG_DIESE;
	ft_pf_conv_hex(pf);
}
