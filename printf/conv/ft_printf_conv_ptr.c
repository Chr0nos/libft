/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:22:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 18:26:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void				ft_printf_convert_ptr(t_printf *pf)
{
	void	*ptr;
	char	buff[24];
	int		len;

	ptr = (void*)pf->raw_value;
	if ((pf->flags & FT_PRINTF_PREC) && (!pf->precision))
	{
		ft_printf_append(pf, "0x", 2);
		return ;
	}
	len = ft_ulltobuff(buff, (unsigned long long)ptr, 16,
		"0123456789abcdef");
	if (ft_printf_isaligned_left(pf))
		ft_printf_padding(pf, ' ', pf->min_field - len - 2);
	ft_printf_append(pf, "0x", 2);
	ft_printf_append(pf, buff, (size_t)len);
	if (pf->flags & FT_PRINTF_PREC)
		ft_printf_padding(pf, '0', pf->precision - len);
}
