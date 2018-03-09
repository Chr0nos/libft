/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_upn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:27:56 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/09 18:00:49 by snicolet         ###   ########.fr       */
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
		return (FT_SF_OK);
	ptr = va_arg(*sf->ap, const char **);
	*ptr = sf->str;
	return (FT_SF_OK);
}
