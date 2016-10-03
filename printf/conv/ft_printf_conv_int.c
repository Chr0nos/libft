/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:23:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/03 16:27:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void					ft_printf_convert_int(t_printf *pf)
{
	char			buff[13];
	const char		*c;
	const int		nb = va_arg(*(pf->ap), int);
	int				len;

	c = buff;
	if (pf->flags & FT_PRINTF_PREC)
	{
		if (nb < 0)
			ft_printf_append(pf, "-", 1);
		else if (pf->flags & FT_PRINTF_FLAG_MORE)
			ft_printf_append(pf, "+", 1);
		c++;
		ft_printf_padding(pf, '0', pf->precision);
	}
	else if ((nb >= 0) && (pf->flags & FT_PRINTF_FLAG_MORE))
		ft_printf_append(pf, "+", 1);
	len = ft_itobuff(buff, nb, 10, "0123456789");
	ft_printf_append(pf, c, (size_t)len);
	pf->lastlen = len;
}
