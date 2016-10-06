/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 23:23:11 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/11 14:42:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	p;
	char			*x;

	if (!(x = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	p = 0;
	while (s[p])
	{
		x[p] = f(p, s[p]);
		p++;
	}
	x[p] = '\0';
	return (x);
}
