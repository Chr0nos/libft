/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:09:11 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/01 15:09:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_scanf_set_int(t_scanf *sf)
{
	int			*result;
	int			len;

	len = 0;
	while (ft_strany(sf->str[len], "\t\n\v\f\r+-"))
		len++;
	while (ft_isdigit(sf->str[len]))
		len++;
	result = (int *)va_arg(*sf->ap, int *);
	*result = ft_atoi(sf->str);
	if (sf->flags & FT_SF_MOD_HH)
		*result = (int)(char)*result;
	else if (sf->flags & FT_SF_MOD_H)
		*result = (int)(short)*result;
	sf->str += len;
	return (1);
}
