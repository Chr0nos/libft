/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 00:49:13 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/09 17:56:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

/*
** this function exists only to check if the sf->str has reached end
** exemple:
** if (ft_sscanf(line, "%d%$") == 2) ...
** will check if there is nothing more than a number in the string
*/

int		ft_scanf_set_end(t_scanf *sf)
{
	return ((sf->format[1]) ? FT_SF_ERROR : FT_SF_OK);
}
