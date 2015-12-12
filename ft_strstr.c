/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:57:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:06:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char *str, const char *item)
{
	size_t		ip;

	if (!*item)
		return (str);
	while (*str)
	{
		ip = 0;
		while (str[ip] == item[ip])
			if (!item[++ip])
				return (str);
		str++;
	}
	return (0);
}
