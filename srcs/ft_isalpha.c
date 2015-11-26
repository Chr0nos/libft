/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:49:55 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/26 12:54:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(const char *str)
{
	while ((*str) && (((*str >= 'a') && (*str <= 'z')) ||
				((*str >= 'A') && (*str <= 'Z'))))
		str++;
	return ((*str ? 0 : 1));
}