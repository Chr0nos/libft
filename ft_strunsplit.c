/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:06:23 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/16 20:47:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strunsplit(char **tab, char separator)
{
	char	*str;
	size_t	size;
	size_t	p;
	size_t	slen;

	size = 0;
	while (tab[size])
		size++;
	if (!(str = (char*)malloc(sizeof(char) * (ft_tabstrlen(tab) + size + 1))))
		return (NULL);
	p = 0;
	slen = 0;
	while (tab[p] != NULL)
	{
		ft_strcpy(str + slen, tab[p]);
		slen += ft_strlen(tab[p]);
		p++;
		if ((p != size) && (separator))
			str[slen++] = separator;
	}
	str[slen] = '\0';
	return (str);
}
