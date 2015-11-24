/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:17:00 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/24 14:53:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memset(char *str, char c, unsigned int n)
{
	while (n--)
		str[n] = c;
}
