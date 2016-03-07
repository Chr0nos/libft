/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtoconst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:20:44 by snicolet          #+#    #+#             */
/*   Updated: 2016/03/07 14:39:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

const void	**ft_tabtoconst(void **tab, size_t size)
{
	const void	**rtab = malloc(sizeof(void *) * size);

	if (!rtab)
		return (NULL);
	while (size--)
		rtab[size] = (const void *)tab[size];
	return (rtab);
}
