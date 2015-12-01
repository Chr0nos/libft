/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:30:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 02:40:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	size_t	p;
	char	*x;

	if (!(x = malloc(sizeof(char) * (n + 1))))
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
