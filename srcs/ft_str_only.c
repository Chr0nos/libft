/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_only.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 19:00:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/20 20:33:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_only(char c, char *list)
{
	while (*list)
	{
		if (c == *list)
			return (1);
		list++;
	}
	return (0);
}

int		ft_str_only_string(char *str, char *list)
{
	while (*str)
	{
		if (!ft_str_only(*str, list))
			return (0);
		str++;
	}
	return (1);
}
