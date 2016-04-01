/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 18:56:07 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/01 19:29:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

int		ft_mfree(unsigned int size, ...)
{
	va_list		ap;

	if (!size)
		return (0);
	va_start(ap, size);
	while (size--)
		free(va_arg(ap, void*));
	va_end(ap);
	return (1);
}
