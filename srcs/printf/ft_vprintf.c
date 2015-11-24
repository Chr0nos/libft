/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:24:21 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/24 16:50:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdarg.h"

void	ft_vprintf(const char *str, va_list *ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				ft_putchar('%');
			else if (*str == 'c')
				ft_putchar(va_arg(*ap, int));
			else if (*str == 's')
				ft_putstr(va_arg(*ap, char*));
			else if (*str == 'd')
				ft_putnbr(va_arg(*ap, int));
		}
		else
			ft_putchar(*str);
		str++;
	}
}
