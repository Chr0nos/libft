/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:24:21 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 20:30:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_error(char **str)
{
	if (!*str)
		return (1);
	while ((ft_strany(**str, " \t\n\v\f\r+0")) && (**str))
		(*str)++;
	if (!*str)
		return (2);
	return (0);
}

int				ft_atoi(char *str)
{
	int		nb;
	int		p;
	int		len;
	char	negative;

	p = 0;
	nb = 0;
	negative = 0;
	if (ft_atoi_error(&str))
		return (0);
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	len = ft_strlen(str);
	while (ft_isdigit(str[p]))
	{
		nb += (str[p] - '0') * (ft_pow(10, len - p - 1));
		p++;
	}
	if (negative)
		nb *= -1;
	return ((str[p]) ? 0 : nb);
}
