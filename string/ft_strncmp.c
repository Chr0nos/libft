/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:46:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 14:31:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	p;

	if (!n)
		return (0);
	n--;
	p = 0;
	while ((p < n) && (s1[p] != '\0') &&
			((unsigned char)s1[p] == (unsigned char)s2[p]))
		p++;
	return ((unsigned char)s1[p] - (unsigned char)s2[p]);
}
