/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:48:41 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/05 18:11:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_printf_convert_octal(t_printf *pf)
{
	char				buff[64];
	int					len;
	uintmax_t			nb;

	if (pf->flags & FT_PRINTF_MOD_H)
		nb = (uintmax_t)(unsigned short)pf->raw_value;
	else if (pf->flags & FT_PRINTF_MOD_HH)
		nb = (uintmax_t)(unsigned char)pf->raw_value;
	else
		nb = (uintmax_t)(int)pf->raw_value;
	if ((pf->flags & FT_PRINTF_FLAG_DIESE) && (nb != 0))
		ft_printf_append(pf, "0", 1);
	len = ft_ulltobuff(buff, (unsigned long long)nb, 8, "012345678");
	ft_printf_append(pf, buff, (size_t)len);
}

void			ft_printf_convert_uloctal(t_printf *pf)
{
	char			buff[64];
	int				len;
	uintmax_t		nb;

	if (pf->flags & (FT_PRINTF_MOD_L | FT_PRINTF_MOD_LL))
		nb = (unsigned long long)pf->raw_value;
	else
		nb = (unsigned long)pf->raw_value;
	if ((pf->flags & FT_PRINTF_FLAG_DIESE) && (nb != 0))
		ft_printf_append(pf, "0", 1);
	len = ft_ulltobuff(buff, (unsigned long long)nb, 8, "012345678");
	ft_printf_append(pf, buff, (size_t)len);
}
