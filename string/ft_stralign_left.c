/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralign_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:43:24 by snicolet          #+#    #+#             */
/*   Updated: 2016/09/30 04:40:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stralign_left(char *buffer, unsigned int len)
{
	const size_t	slen = ft_strlen(buffer);
	size_t			diff;

	if (slen >= len)
		return ;
	diff = len - slen;
	buffer += slen;
	ft_memset(buffer, ' ', diff);
	buffer[diff] = '\0';
}
