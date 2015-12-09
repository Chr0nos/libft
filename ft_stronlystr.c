/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronlystr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:51:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/30 15:52:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stronlystr(char *str, char *list)
{
	while (*str)
	{
		if (!ft_str_only(*str, list))
			return (0);
		str++;
	}
	return (1);
}
