/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralign_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:48:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/07 03:11:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stralign_right(char *buffer, unsigned int len)
{
	size_t				slen;
	size_t				diff;

	slen = ft_strlen(buffer);
	if (slen >= len)
		return ;
	diff = len - slen;
	ft_memmove(buffer + diff, buffer, slen);
	ft_memset(buffer, ' ', diff);
}
