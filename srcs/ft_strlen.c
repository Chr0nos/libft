/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:04:03 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 13:09:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	if (!str)
		return (0);
	c = 0;
	while ((*str) && ((str++)))
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
