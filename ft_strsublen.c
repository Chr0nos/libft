/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsublen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:33:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:54:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strsublen(const char *str, char c)
{
	size_t	counter;

	counter = 0;
	while ((*str) && (*str != c) && (str++))
		counter++;
	return (counter);
}
