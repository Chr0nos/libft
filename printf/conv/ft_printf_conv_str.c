/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:24:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 01:30:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void					ft_printf_convert_str(t_printf *pf)
{
	const char		*str = va_arg(*(pf->ap), char *);
	size_t			len;

	if (pf->flags & FT_PRINTF_PREC)
	{
		len = 0;
		while ((*str) && (len < (size_t)pf->precision))
			len++;
	}
	else
		len = ft_strlen(str);
	ft_printf_append(pf, str, len);
}
