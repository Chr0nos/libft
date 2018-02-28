/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:27:02 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 15:50:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strremove(char *s, const char *list)
{
	size_t	p;
	size_t	len;

	p = 0;
	len = ft_strlen(s);
	while (s[p])
	{
		if (ft_strchr((char*)(size_t)list, s[p]))
			ft_memmove((void*)&s[p], (void*)&s[p + 1], len--);
		else
			p++;
	}
	return (s);
}
