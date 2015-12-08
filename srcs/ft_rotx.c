/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:11:35 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/08 13:12:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rotx(char *s, int x)
{
	while (*s)
	{
		if ((*s >= 'a') && (*s <= 'z'))
			*s = 'a' + ((*s - 'a' + x) % 26);
		else if ((*s >= 'A') && (*s <= 'Z'))
			*s = 'A' + ((*s - 'A' + x) % 26);
		s++;
	}
}
