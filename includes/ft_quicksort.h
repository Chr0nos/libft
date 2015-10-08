/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 11:59:22 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/08 23:47:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUICKSORT_H
# define FT_QUICKSORT_H
#include "ft.h"

t_size	ft_quicksort_part(void **tab, t_size start, t_size end,	int (*cmp)());
void	ft_quicksort(void **tab, t_size start, t_size end, int (*cmp)());

#endif
