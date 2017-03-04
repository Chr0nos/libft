/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:09:47 by snicolet          #+#    #+#             */
/*   Updated: 2017/03/04 11:15:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_numbits(unsigned int nb)
{
	int		len;

	len = 1;
	while ((nb = nb >> 1))
		len++;
	return (len);
}

/*
** return the lenght (in char) of a wchar
** range can be 1 to 4
*/

int					ft_wcharlen(const wchar_t c)
{
	register const int		n = ft_numbits((unsigned int)c);

	if (n > 16)
		return (4);
	if (n > 11)
		return (3);
	if (n > 7)
		return (2);
	return (1);
}
