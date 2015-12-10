/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brainfuck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:46:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/10 19:14:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*brloop(const char *str)
{
	while ((*str) && (*str != ']'))
	{
		if (*str == '[')
			str = brloop(str + 1);
		else
			str++;
	}
	if (*str == ']')
		str++;
	return (str);
}

char				*ft_brainfuck(const char *str, unsigned char *ptr)
{
	const char	*start;

	start = str;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			(*ptr)++;
		else if (*str == '-')
			(*ptr)--;
		else if (*str == '.')
			ft_putchar(*ptr);
		else if (*str == ',')
			ft_putendl("warning: ',' instruction are not supported yet");
		else if ((*str == '[') && (*ptr != 0))
			str = ft_brainfuck(str + 1, ptr);
		else if (*str == '[')
			str = brloop(str + 1) - 1;
		else if ((*str == ']') && (*ptr == 0))
			break ;
		else if (*str == ']')
			str = start - 1;
		str++;
	}
	return ((char*)str);
}
