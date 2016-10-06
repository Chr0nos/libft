/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atonum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 21:36:40 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 21:40:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atonum(const char *str, int *nb)
{
	const char	*origin = str;

	*nb = 0;
	while (ft_isdigit(*str))
		*nb = (*nb * 10) + (*(str++) - '0');
	return ((int)((size_t)str - (size_t)origin));
}
