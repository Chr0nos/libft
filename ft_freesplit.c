/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 20:46:15 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 21:07:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_freesplit(char **split)
{
	int		p;

	p = 0;
	while (split[p])
		free(split[p++]);
}

void	ft_freesplit_multi(char ***split, int size)
{
	if (size < 0)
		return ;
	while (size--)
		ft_freesplit(split[size]);
}
