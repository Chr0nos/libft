/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrany.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:09:42 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 15:50:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrany(char *str, const char *list)
{
	while (*str)
	{
		if (ft_strchr((char*)(size_t)list, *str))
			return (str);
		str++;
	}
	return (NULL);
}
