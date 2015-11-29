/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:29:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/29 17:29:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list		*ft_list_create_elem(void *data)
{
	t_list	*x;

	x = malloc(sizeof(t_list));
	if (x)
	{
		x->data = data;
		x->next = 0;
	}
	return (x);
}
