/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_wsize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:23:27 by snicolet          #+#    #+#             */
/*   Updated: 2018/12/07 18:24:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_printf_conv_wsize(struct s_printf *pf)
{
	size_t              len;
	char                buf[80];

	len = ft_printf_append(pf, buf,
		(size_t)ft_wsize((size_t)pf->raw_value, buf, 80));
	pf->slen += len;
}
