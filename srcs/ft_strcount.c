/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 14:04:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/30 15:49:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcount(char *str, char c)
{
	int		counter;

	counter = 0;
	while (*str)
	{
		if (*str == c)
			counter++;
		str++;
	}
	return (counter);
}
