/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cryptxor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 09:28:06 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/16 09:43:06 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cryptxor(char *str, size_t slen, const char *key)
{
	const char	*key_start = key;
	char		*start;

	start = str;
	while (slen--)
	{
		*(str++) ^= *(key++);
		if (!*key)
			key = key_start;
	}
	return (start);
}
