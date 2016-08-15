/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:39:07 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 14:28:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(char *s, int c)
{
	const char	*start = s;

	while (*(s++))
		;
	while ((--s != start) && (*s != c))
		;
	return ((*s == c) ? s : NULL);
}
