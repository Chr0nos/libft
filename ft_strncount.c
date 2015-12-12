/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:47:56 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:07:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncount(char *str, char c, unsigned int n)
{
	int		counter;

	counter = 0;
	while ((*str) && (n--))
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}
