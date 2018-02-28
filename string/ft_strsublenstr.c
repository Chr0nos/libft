/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsublenstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:19:35 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 15:48:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strsublenstr(const char *str, const char *separators)
{
	size_t		p;

	p = 0;
	while (str[p])
	{
		if (ft_strchr((char*)(size_t)separators, str[p]))
			return (p);
		p++;
	}
	return (p);
}
