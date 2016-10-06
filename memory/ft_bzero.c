/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 21:36:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 18:48:09 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t		p;

	p = 0;
	while ((p < n) && ((n - p) % 8))
		((unsigned char *)s)[p++] = 0;
	while (p < n)
	{
		*(void**)((unsigned long)s + p) = NULL;
		p += 8;
	}
}
