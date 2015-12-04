/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:24:21 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/04 13:27:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_error(char **str)
{
	while ((ft_strany(**str, " \t\n\v\f\r")) && (**str))
		(*str)++;
	if (!*str)
		return (2);
	return (0);
}

int				ft_atoi(char *str)
{
	int		nb;
	int		p;
	char	negative;

	p = 0;
	nb = 0;
	negative = 0;
	if (ft_atoi_error(&str))
		return (0);
	if (*str == '+')
		str++;
	else if ((*str == '-') && (*(str++)))
		negative = 1;
	while (ft_isdigit(str[p]))
		nb = (nb * 10) + (str[p++] - '0');
	return ((negative) ? (nb * -1) : nb);
}
