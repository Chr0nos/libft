/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strseek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 18:12:29 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/25 19:33:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the N occurence of "c" in a string
** example: ft_strseek("i like bananas and nuggets", 'n', 3)
** will return the pointer to : "nuggets"
*/

const char	*ft_strseek(const char *src, char c, const int n)
{
	if ((!src) || (!*src))
		return (NULL);
	if (n < 0)
		return (src);
	if (!src[1])
		return (NULL);
	return (ft_strseek(
		ft_strchr((char*)(unsigned long)(src + 1), c), c, n - 1));
}
