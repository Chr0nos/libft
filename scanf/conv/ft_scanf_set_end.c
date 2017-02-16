/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 00:49:13 by snicolet          #+#    #+#             */
/*   Updated: 2017/02/16 12:49:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

/*
** this function exists only to check if the sf->str has reached end
** exemple:
** if (ft_sscanf(line, "%d%e") == 2) ...
** will check if there is nothing more than a number in the string
*/

int		ft_scanf_set_end(t_scanf *sf)
{
	if (sf->format[1])
		sf->flags |= FT_SF_ERROR;
	return (1);
}
