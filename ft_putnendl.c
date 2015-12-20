/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:57:24 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/20 16:03:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnendl(const char *s, size_t n)
{
	const size_t	l = ft_strlen(s);

	write(1, s, (l > n) ? n : l);
	ft_putchar('\n');
}
