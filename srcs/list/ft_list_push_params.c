/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:34:36 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/31 19:38:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*lst;

	lst = 0;
	while (ac--)
		ft_list_push_back(&lst, av[ac]);
	return (lst);
}
