/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:11:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/01 16:58:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_scanf_set_str(t_scanf *sf)
{
	int		len;

	len = (int)ft_strlen(sf->str);
	if (!(sf->flags & FT_SF_FLAG_SKIP))
		*va_arg(*sf->ap, char **) = ft_memdup(sf->str, (size_t)len + 1);
	sf->str += len;
	return (1);
}
