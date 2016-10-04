/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:59:08 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 22:11:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_printf_convert_wchar(t_printf *pf)
{
	char			buff[4];
	const wchar_t	nb = (wchar_t)pf->raw_value;

	if (nb <= 127)
		ft_printf_convert_char(pf);
	else
		ft_printf_append(pf, buff, (size_t)ft_buffwchar(nb, buff));
}
