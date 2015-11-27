/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 10:40:58 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 13:46:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_putnbr(int nb)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	if (tmp)
	{
		ft_putstr(tmp);
		free(tmp);
	}
}
