/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:21:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 22:54:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(const wchar_t *s)
{
	size_t		len;

	len = 0;
	while (*s)
		len += (size_t)ft_wcharlen(*(s++));
	return (len);
}
