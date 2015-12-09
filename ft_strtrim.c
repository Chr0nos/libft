/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:30:04 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 16:24:50 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len++;
	while ((i < len) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	len = len - i;
	if (!(str = ft_strsub((char *)s, i, len)))
		return (NULL);
	str[len] = 0;
	return (str);
}
