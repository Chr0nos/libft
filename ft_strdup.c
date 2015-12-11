/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 22:07:06 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/11 14:43:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (0);
	return (ft_strcpy(dest, str));
}
