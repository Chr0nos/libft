/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:11:48 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/02 00:44:33 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_scanf_set_str(t_scanf *sf)
{
	size_t		len;
	char		*str;

	len = (sf->flags & FT_SF_FLAG_PREC) ?
		ft_strplen(sf->str, &sf->str[sf->precision]) :
		ft_strlen(sf->str);
	if (!(sf->flags & FT_SF_FLAG_SKIP))
	{
		if (!(str = malloc(sizeof(char) * (len + 1))))
		{
			sf->flags |= FT_SF_ERROR | FT_SF_QUIT;
			return (1);
		}
		ft_memcpy(str, sf->str, len);
		str[len] = '\0';
		*va_arg(*sf->ap, char **) = str;
	}
	sf->str += len;
	return (1);
}