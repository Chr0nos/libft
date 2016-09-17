/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrany.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:09:42 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/17 17:18:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrany(char *str, const char *list)
{
	while (*str)
	{
		if (ft_strany(*str, list))
			return (str);
		str++;
	}
	return (NULL);
}
