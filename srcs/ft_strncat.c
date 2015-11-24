/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:29:12 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/24 17:36:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*x;

	x = dest;
	while (*dest)
		dest++;
	ft_strncpy(dest, (char*)src, n);
	return (x);
}
