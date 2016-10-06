/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strany_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:41:06 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 17:05:42 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strany_string(const char *src, const char *list)
{
	while (*src)
	{
		if (ft_strany(*src, list))
			return (1);
		src++;
	}
	return (0);
}
