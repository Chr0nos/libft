/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrrpos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:19:16 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/11 17:29:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrrpos(const char *str, const char c)
{
	size_t	p;

	p = ft_strlen(str);
	while (p--)
		if (str[p] == c)
			return ((int)p);
	return (-1);
}
