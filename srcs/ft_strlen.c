/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:04:03 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/24 20:19:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

size_t	ft_strlen(char *str)
{
	int		c;

	c = 0;
	while ((*str) && ((str++)))
		c++;
	return (c);
}

size_t	ft_strsublen(char *str, char c)
{
	int		counter;

	counter = 0;
	while ((*str) && (*str != c) && (str++))
		counter++;
	return (counter);
}
