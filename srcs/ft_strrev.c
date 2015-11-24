/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 12:14:01 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/17 19:33:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		pos_reverse;
	int		pos_normal;
	char	tmp;

	pos_reverse = ft_strlen(str) - 1;
	pos_normal = 0;
	while (pos_normal < pos_reverse)
	{
		tmp = str[pos_normal];
		str[pos_normal] = str[pos_reverse];
		str[pos_reverse] = tmp;
		pos_normal++;
		pos_reverse--;
	}
	return (str);
}
