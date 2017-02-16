/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsublen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:33:55 by snicolet          #+#    #+#             */
/*   Updated: 2017/02/16 12:27:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strsublen(const char *str, char c)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while ((*str) && (*str != c) && (str++))
		counter++;
	return (counter);
}
