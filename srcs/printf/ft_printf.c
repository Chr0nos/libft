/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 16:12:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/24 12:54:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdarg.h>

void	ft_printf(const char* str, ...)
{
	va_list args;

	va_start(args, str);
	ft_vprintf(str, &args);
	va_end(args);
}
