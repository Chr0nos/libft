/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 23:01:09 by snicolet          #+#    #+#             */
/*   Updated: 2016/02/26 23:20:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>

void	ft_putfloat(float nb)
{
	char	buffer[32];

	write(1, buffer, (size_t)ft_ftobuff(buffer, nb, 10, "0123456789"));
}
