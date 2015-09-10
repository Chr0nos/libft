/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 14:04:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/27 12:05:13 by snicolet         ###   ########.fr       */
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
