/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wstr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:14:00 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 22:26:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_printf_convert_wstr(t_printf *pf)
{
	char				buff[4];
	const unsigned int	*str = (unsigned int *)pf->raw_value;

	while (*str)
		ft_printf_append(pf, buff,
			(size_t)ft_buffwchar(*(const wchar_t*)(str++), buff));
}
