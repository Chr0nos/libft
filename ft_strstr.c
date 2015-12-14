/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:57:02 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 14:21:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char *str, const char *item)
{
	size_t		ip;

	if (*item == '\0')
		return (str);
	while (*str)
	{
		ip = 0;
		while ((str[ip] != '\0') && (str[ip] == item[ip]))
			if (!item[++ip])
				return (str);
		str++;
	}
	return (0);
}
