/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_upn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:27:56 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/20 01:12:02 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** set the current address of sf->str into the user given pointer
*/

int		ft_scanf_set_upn(t_scanf *sf)
{
	const char		**ptr;

	if (sf->flags & FT_SF_FLAG_SKIP)
		return (1);
	ptr = va_arg(*sf->ap, const char **);
	*ptr = sf->str;
	return (1);
}
