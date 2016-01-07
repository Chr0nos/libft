/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:05:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 16:06:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strsplit_count(const char *str, char c)
{
	size_t	len;

	len = 0;
	while ((*str) && (++len))
	{
		while (*str == c)
			str++;
		if (!*str)
			return (len + 1);
		else
			str++;
	}
	return (len + 1);
}
