/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strforf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 21:04:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/03 18:27:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char		*ft_strforf(const char *str, const char *sep, int *len)
{
	const char	*origin = str;

	while ((*str) && (!ft_strany(*str, sep)))
		str++;
	*len = (int)((size_t)str - (size_t)origin);
	if (!*str)
		return (NULL);
	return (str);
}
