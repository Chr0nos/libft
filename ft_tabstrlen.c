/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 19:00:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/16 19:02:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_tabstrlen(char **tab)
{
	size_t	len;

	len = 0;
	while (*tab != NULL)
	{
		len += ft_strlen(*tab);
		tab++;
	}
	return (len);
}
