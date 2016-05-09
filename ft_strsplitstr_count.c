/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:10:04 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/09 18:13:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strsplitstr_count(const char *str, const char *separators)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		while (ft_strany_string(str, separators))
			str++;
		if (!str)
			return (len + 1);
		else
			str++;
	}
	return (len + 1);
}
