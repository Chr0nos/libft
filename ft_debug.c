/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 12:16:03 by dboudy            #+#    #+#             */
/*   Updated: 2016/08/29 12:40:11 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void		ft_putnchar(char c, unsigned int n)
{
	while (n--)
		write(1, &c, 1);
}

void		ft_debug_pstr(const char *s, unsigned int lvl)
{
	ft_putnchar('\t', lvl);
	ft_putstr(s);
}
