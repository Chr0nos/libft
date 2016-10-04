/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wstr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:14:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 23:23:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_printf_convert_wstr(t_printf *pf)
{
	char				buff[4];
	const wchar_t		*str = (wchar_t*)pf->raw_value;
	int					len;

	if (!str)
	{
		ft_printf_append(pf, "(null)", 6);
		return ;
	}
	while (*str)
	{
		len = ft_buffwchar(*str, buff);
		ft_printf_append(pf, buff, (size_t)len);
		str++;
	}
}
