/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_align_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:27:13 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/03 16:47:01 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_align_right(char *str, char fill, size_t len)
{
	size_t	left;
	size_t	size;

	size = ft_strlen(str);
	left = len - size;
	while (left-- > 0)
		ft_putchar(fill);
	write(1, str, len);
}
