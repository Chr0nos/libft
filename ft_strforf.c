/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strforf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 21:04:47 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/29 21:29:57 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strforf(char **target, const char *sep)
{
	char		*str;
	int			len;

	if (!*target)
		return (-1);
	str = *target;
	while ((*str) && (!ft_strany(*str, sep)))
		str++;
	len = (int)((size_t)str - (size_t)*target);
	if ((!*str) && (len == 0))
		return (-1);
	*target = str;
	return (len);
}
