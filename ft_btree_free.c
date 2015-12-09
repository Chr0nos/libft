/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:50:50 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/09 18:56:34 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_btree_free(t_btree **root)
{
	if (!*root)
		return ;
	if ((*root)->left)
		ft_btree_free(&(*root)->left);
	if ((*root)->right)
		ft_btree_free(&(*root)->right);
	free(*root);
	*root = 0;
}
