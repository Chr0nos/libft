/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:32:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/01 15:38:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_scanf_set_float_len(const char *str)
{
	int		len;

	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	if (str[len] == '.')
	{
		len++;
		while (ft_isdigit(str[len]))
			len++;
	}
	return (len);
}

int				ft_scanf_set_float(t_scanf *sf)
{
	float	*value;

	value = va_arg(*sf->ap, float *);
	*value = (float)ft_atod(sf->str);
	sf->str += ft_scanf_set_float_len(sf->str);
	return (1);
}
