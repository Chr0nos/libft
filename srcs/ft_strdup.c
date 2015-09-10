/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 22:07:06 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/24 01:10:47 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (0);
	return (ft_strcpy(dest, str));
}
