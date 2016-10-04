/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:22:22 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/04 20:03:30 by snicolet         ###   ########.fr       */
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
	*(unsigned short *)(unsigned long)buff =
		*(unsigned short*)(unsigned long)"0x";
	len = ft_ulltobuff(&buff[2], (unsigned long long)ptr, 16,
		"0123456789abcdef");
	ft_printf_append(pf, buff, (size_t)len + 2);
}
