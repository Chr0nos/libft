/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 23:48:03 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/03 13:45:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_scanf_debug(const t_scanf *sf)
{
	ft_printf("%s%p%s%p%s%s%s%b%s%d%s%u%s%d\n" ,
		"string: ", sf->str,
		" str origin: ", sf->str_origin,
		" format: [", sf->format,
		"] flags: ", sf->flags,
		" precision: ", sf->precision,
		" args done: ", sf->arg_done,
		" max len: ", sf->maxlen);
}
