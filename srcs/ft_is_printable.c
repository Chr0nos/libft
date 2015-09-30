/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_printable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 20:19:33 by pgrassin          #+#    #+#             */
/*   Updated: 2015/09/03 20:42:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_is_printable(char c)
{
	if ((c >= 32 && c <= 126) || (c == '\n'))
		return (1);
	return (0);
}

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!ft_is_printable(*(str++)))
			return (0);
	}
	return (1);
}
