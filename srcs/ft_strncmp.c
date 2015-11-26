/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:46:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/26 12:48:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 == *s2) && (n--))
		(s1++, s2++);
	return (*s1 - *s2);
}