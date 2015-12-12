/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:07:21 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/12 21:32:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_match(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (ft_match(s1, s2 + 1));
		return ((*s2 == 0 ? 1 : 0));
	}
	else if (*s2 == '*')
	{
		if (s2[1])
		{
			if (!s2[1])
				return (1);
			else if (s2[1] == '*')
				return (ft_match(s1, s2 + 1));
			else if (s2[1] == *s1)
				return (ft_match(s1 + 1, s2 + 2));
			return (ft_match(s1 + 1, s2));
		}
		return (1);
	}
	else if (*s2 == *s1)
		return (ft_match(s1 + 1, s2 + 1));
	return (0);
}
