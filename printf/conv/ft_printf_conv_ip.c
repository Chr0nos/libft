/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:53:23 by snicolet          #+#    #+#             */
/*   Updated: 2018/12/07 18:24:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_printf_conv_ip(struct s_printf *pf)
{
    const unsigned int      ip = (int)pf->raw_value;

    ft_printf_stack(pf, "%u.%u.%u.%u",
        (ip & 0xff000000) >> 24,
        (ip & 0x00ff0000) >> 16,
        (ip & 0x0000ff00) >> 8,
        (ip & 0x000000ff)
    );
}
