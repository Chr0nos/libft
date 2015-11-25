/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:57:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/25 16:25:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

char	*ft_strstr(const char *str, const char *item)
{
	size_t		ip;

	if (!*item)
		return ((char*)str);
	while (*str)
	{
		ip = 0;
		while (str[ip] == item[ip])
			if (!item[++ip])
				return ((char*)str);
		str++;
	}
	return (0);
}
