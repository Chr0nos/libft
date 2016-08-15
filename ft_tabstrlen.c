/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 19:00:15 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 17:02:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_tabstrlen(const char **tab)
{
	size_t	len;

	len = 0;
	while (*tab != NULL)
		len += ft_strlen(*(tab++));
	return (len);
}
