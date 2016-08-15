/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:06:23 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/15 17:11:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strunsplit(const char **tab, char separator)
{
	char			*str;
	const size_t	size = ft_tabcount((void**)(unsigned long)tab) - 1;
	size_t			p;
	size_t			slen;
	size_t			len;

	if (!(str = (char*)malloc(sizeof(char) * (ft_tabstrlen(tab) + size + 1))))
		return (NULL);
	p = 0;
	slen = 0;
	while (tab[p] != NULL)
	{
		len = ft_strlen(tab[p]);
		ft_memcpy(str + slen, tab[p++], len);
		slen += len;
		if ((p != size) && (separator))
			str[slen++] = separator;
	}
	str[slen] = '\0';
	return (str);
}
