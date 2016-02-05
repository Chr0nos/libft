/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:48:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/05 19:28:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_align_left(char *buffer, unsigned int len)
{
	size_t				slen;
	size_t				diff;

	slen = ft_strlen(buffer);
	if (slen >= len)
		return ;
	diff = len - slen;
	ft_memmove(buffer + diff, buffer, slen);
	while (diff--)
		buffer[diff] = ' ';
}
