/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:14:01 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:53:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strrev(char *str)
{
	size_t	pos_reverse;
	size_t	pos_normal;
	char	tmp;

	pos_reverse = ft_strlen(str) - 1;
	pos_normal = 0;
	while (pos_normal < pos_reverse)
	{
		tmp = str[pos_normal];
		str[pos_normal++] = str[pos_reverse];
		str[pos_reverse--] = tmp;
	}
	return (str);
}
