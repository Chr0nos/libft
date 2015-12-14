/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 20:20:52 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 20:23:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strreplace(char *s, char what, char by)
{
	size_t	p;

	p = 0;
	while (s[p])
	{
		if (s[p] == what)
			s[p] = by;
		p++;
	}
	return (s);
}
