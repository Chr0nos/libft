/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2015/12/05 15:44:05 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/05 15:45:57 by snicolet         ###   ########.fr       */
=======
/*   Created: 2015/12/05 17:48:52 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/05 17:50:03 by snicolet         ###   ########.fr       */
>>>>>>> dev
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strchrpos(const char *s, const char c)
{
	size_t	p;

	p = 0;
	while (s[p])
		if (s[p++] == c)
			return (p - 1);
	return (0);
}
