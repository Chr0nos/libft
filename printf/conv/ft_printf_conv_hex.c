/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:58:53 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 03:11:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void			ft_printf_convert_hex(t_printf *pf)
{
	char			buff[24];
	int				len;
	const uintmax_t	nb = ft_printf_conv_uint_getnb(pf);

	len = ft_ulltobuff(buff, (unsigned long long)nb, 16, "0123456789abcdef");
	ft_printf_append(pf, buff, (size_t)len);
}

void			ft_printf_convert_uphex(t_printf *pf)
{
	char				buff[24];
	int					len;
	const uintmax_t		nb = ft_printf_conv_uint_getnb(pf);

	len = ft_ulltobuff(buff, (unsigned long long)nb, 16, "0123456789ABCDEF");
	ft_printf_append(pf, buff, (size_t)len);
}
