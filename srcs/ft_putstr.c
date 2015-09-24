/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:02:21 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/24 17:25:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	ft_putstr_align_right(char *str, char fill, t_size len)
{
	t_size	left;
	t_size	size;

	size = ft_strlen(str);
	left = len - size;
	while (left-- > 0)
		ft_putchar(fill);
	write(1, str, len);
}
