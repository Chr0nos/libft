/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 23:05:54 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/17 23:08:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_scanf_set_percent(t_scanf *sf)
{
	if (*sf->str == '%')
		sf->str++;
	else
		sf->flags |= FT_SF_ERROR;
	return (1);
}
