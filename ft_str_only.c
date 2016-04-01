/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_only.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 19:00:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/04/01 15:34:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_only(const char c, const char *list)
{
	while (*list)
	{
		if (c != *list)
			return (0);
		list++;
	}
	return (1);
}
