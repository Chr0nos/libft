/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:42:17 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 14:46:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*x;

	if (!(x = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(x + start, s, len);
	x[len] = '\0';
	return (x);
}