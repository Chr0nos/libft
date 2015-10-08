/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 11:59:22 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/08 17:37:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUICKSORT_H
# define FT_QUICKSORT_H
#include "ft.h"

typedef struct	s_quicksort
{
	void		**tab;
	int			(*cmp)();
}				t_quicksort;

t_size			ft_quicksort_part(t_quicksort *s, t_size start, t_size end);
void			ft_quicksort(void **tab, t_size start, t_size end,
				int (*cmp)());

#endif
