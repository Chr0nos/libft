/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:38:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/12 18:06:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** the malloc printf variant:
** this function will malloc in *ret and return the len;
** the string will be null terminated
** in case of error the function will return -1 and NULL will be set in *ret
*/

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	t_printf	pf;

	if (!(pf.buff_asprintf = malloc(FT_PF_ASIZE)))
		return (-1);
	va_start(ap, format);
	ft_printf_init(&pf, &ap);
	pf.flags |= FT_PF_ALLOC | FT_PF_NOWRITE;
	pf.space_left = FT_PF_ASIZE;
	pf.buff_start = pf.buff_asprintf;
	ft_printf_engine(format, &pf);
	va_end(ap);
	ft_printf_append(&pf, "\0", 1);
	*ret = pf.buff_asprintf;
	if (pf.flags & FT_PF_ERROR)
	{
		if (pf.buff_asprintf)
			free(pf.buff_asprintf);
		*ret = NULL;
		return (-1);
	}
	return ((int)pf.size);
}
