/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:42:33 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/06 17:46:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_udigit_len(uintmax_t nb, unsigned int base)
{
	int			len;

	len = 1;
	while ((nb) && (nb /= base))
		len++;
	return (len);
}

int		ft_digit_len(intmax_t nb, unsigned int base)
{
	return (ft_udigit_len((unsigned)((nb < 0) ? -nb : nb), base));
}
