/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:03:04 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/07 00:23:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*malloc(size_t size)
{
	return (ft_malloc(size));
}

void	free(void *ptr)
{
	ft_free(ptr);
}

void	*realloc(void *ptr, size_t size)
{
	return (ft_realloc(ptr, size));
}
