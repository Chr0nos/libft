/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:09:59 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/02 13:28:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strindexof(const char *str, char c)
{
	size_t	p;

	p = 0;
	while (str[p])
	{
		if (str[p] == c)
			return (p);
		p++;
	}
	return (0);
}
