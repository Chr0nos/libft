/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 16:12:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 11:13:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	ft_vprintf(str, &args);
	va_end(args);
}
