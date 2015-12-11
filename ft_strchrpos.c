/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:28:50 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/07 19:29:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchrpos(const char *s, const char c)
{
	int		p;

	p = 0;
	while (s[p])
		if (s[p++] == c)
			return (p - 1);
	return (-1);
}