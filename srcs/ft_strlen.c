/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:04:03 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 18:09:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

size_t	ft_strsublen(char *str, char c)
{
	size_t	counter;

	counter = 0;
	while ((*str) && (*str != c) && (str++))
		counter++;
	return (counter);
}
