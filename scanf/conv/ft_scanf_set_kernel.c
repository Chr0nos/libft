/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_set_kernel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:57:25 by snicolet          #+#    #+#             */
/*   Updated: 2016/11/06 16:24:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_scanf_set_kernel(t_scanf *sf)
{
	void		(*kernel)(t_scanf *);

	kernel = (void(*)(t_scanf*))va_arg(*sf->ap, void *);
	kernel(sf);
	return (1);
}
