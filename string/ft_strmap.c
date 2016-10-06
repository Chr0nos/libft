/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 23:00:32 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/11 14:42:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*x;
	char	*x_base;

	if (!(x = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	x_base = x;
	while (*s)
		*(x++) = f(*(s++));
	*x = '\0';
	return (x_base);
}
