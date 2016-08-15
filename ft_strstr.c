/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:57:02 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 13:33:14 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char *str, const char *item)
{
	const size_t	ilen = ft_strlen(item);

	if (!ilen)
		return (str);
	while (*str)
	{
		if (!ft_memcmp(str, item, ilen))
			return (str);
		str++;
	}
	return (NULL);
}
