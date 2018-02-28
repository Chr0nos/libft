/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:30:04 by snicolet          #+#    #+#             */
/*   Updated: 2018/02/28 15:46:35 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	char			*str;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s) - 1;
	while (ft_strchr(" \t\n\r\v\f", s[len]))
		len--;
	len++;
	while ((i < len) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	len = len - i;
	if (!(str = ft_strsub(s, i, len)))
		return (NULL);
	str[len] = 0;
	return (str);
}
