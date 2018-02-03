/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_strcmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:05:42 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/03 15:18:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** will read into the sf->str for a given char *
** example: ft_sscanf(line, "%s", some_string);
*/

int			ft_scanf_set_strcmp(t_scanf *sf)
{
	const char		*str = va_arg(*sf->ap, const char *);

	while ((*str) && (*str == *sf->str))
	{
		sf->str++;
		str++;
	}
	if ((*str) && (*str != *sf->str))
		sf->flags |= FT_SF_QUIT | FT_SF_ERROR;
	return (1);
}
