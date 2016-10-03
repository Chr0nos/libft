/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 17:45:30 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 19:50:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *src, char c)
{
	const size_t	size = ft_strsublen(src, c);
	char			*dest;

	if ((!size) || (!(dest = ft_memdup(src, size))))
		return (NULL);
	dest[size] = '\0';
	return (dest);
}
