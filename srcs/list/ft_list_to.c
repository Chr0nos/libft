/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 11:56:56 by snicolet          #+#    #+#             */
/*   Updated: 2015/09/10 19:23:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include <stdlib.h>

char	*ft_list_to_char(t_list *lst, char c)
{
	char	*str;
	int		len;
	int		pos;
	int		size;

	size = ft_list_strlen(lst) + ft_list_size(lst);
	pos = 0;
	str = malloc(sizeof(char) * (size + 1));
	while (lst)
	{
		if (lst->data)
		{
			len = ft_strlen((char*)lst->data);
			ft_strncpy(str + pos, (char*)lst->data, len);
			pos += len;
			if (c != 0)
				str[pos++] = c;
		}
		lst = lst->next;
	}
	str[--pos] = '\0';
	return (str);
}
