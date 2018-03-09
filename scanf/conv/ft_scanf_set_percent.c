/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 23:05:54 by snicolet          #+#    #+#             */
/*   Updated: 2018/03/09 18:03:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_scanf_set_percent(t_scanf *sf)
{
	if (*sf->str != '%')
		return (FT_SF_ERROR);
	sf->str++;
	return (FT_SF_OK);
}
