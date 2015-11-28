/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:46:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/28 15:10:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	p;

	p = 0;
	while ((s1[p] != '\0') && (s1[p] == s2[p]) && (p < n))
		p++;
	return ((unsigned char)s1[p] - (unsigned char)s2[p]);
}
