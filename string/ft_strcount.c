/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 14:04:10 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/27 21:11:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strcount(const char *str, char c)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}
