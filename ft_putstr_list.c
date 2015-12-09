/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 15:45:38 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/24 16:11:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_list(char **list, int size, char c)
{
	int		p;

	p = 0;
	while (p < size)
	{
		ft_putstr(list[p++]);
		if (c)
			ft_putchar(c);
	}
}
