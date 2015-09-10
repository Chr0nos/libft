/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 17:37:05 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/20 18:55:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strany(char c, char *list)
{
	while (*list)
	{
		if (*list == c)
			return (1);
		list++;
	}
	return (0);
}

int		ft_strany_string(char *src, char *list)
{
	while (*src)
	{
		if (ft_strany(*src, list))
			return (1);
		src++;
	}
	return (0);
}
