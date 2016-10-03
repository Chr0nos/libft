/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 12:27:50 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 14:30:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		p;

	p = 0;
	while (((unsigned char)s1[p]) &&
			((unsigned char)s1[p] == (unsigned char)s2[p]))
		p++;
	return ((unsigned char)s1[p] - (unsigned char)s2[p]);
}
