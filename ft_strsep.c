/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:25:55 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/17 17:42:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **str, const char *delim)
{
	register char	*s;
	register char	*start;

	if (!*str)
		return (NULL);
	start = *str;
	s = ft_strchrany(*str, delim);
	if (!s)
		*str = NULL;
	else
	{
		*(s++) = '\0';
		*str = s;
	}
	return (start);
}
