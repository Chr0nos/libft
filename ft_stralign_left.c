/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralign_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:43:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/07 14:43:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stralign_left(char *buffer, unsigned int len)
{
	size_t	slen;
	size_t	diff;
	size_t	p;

	slen = ft_strlen(buffer);
	if (slen >= len)
		return ;
	diff = len - slen;
	p = 0;
	buffer += slen;
	while (p < diff)
		buffer[p++] = ' ';
	buffer[p] = '\0';
}
