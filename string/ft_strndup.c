/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:30:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:26:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	size_t	p;
	char	*x;

	if (!(x = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	p = 0;
	while ((s[p]) && (p < n))
	{
		x[p] = s[p];
		p++;
	}
	x[p] = '\0';
	return (x);
}
