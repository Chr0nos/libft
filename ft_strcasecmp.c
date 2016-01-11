/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:01:32 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/11 15:01:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	int		p;

	p = 0;
	while ((s1[p]) && (ft_tolower(s1[p]) == ft_tolower(s2[p])))
		p++;
	return (ft_tolower(s1[p]) - ft_tolower(s2[p]));
}
