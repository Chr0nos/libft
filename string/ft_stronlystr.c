/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronlystr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:51:34 by snicolet          #+#    #+#             */
/*   Updated: 2017/08/28 19:34:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stronlystr(char *str, char *list)
{
	while (*str)
	{
		if (!ft_strchr(list, *str))
			return (0);
		str++;
	}
	return (1);
}
