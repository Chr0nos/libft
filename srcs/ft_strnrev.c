/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:39:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 10:53:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

char	*ft_strnrev(char *str, size_t n)
{
	size_t			p;
	char			tmp;

	p = 0;
	while (p < n)
	{
		tmp = str[p];
		str[p] = str[n--];
		str[p++] = tmp;
	}
	return (str);
}
