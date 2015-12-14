/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brainfuck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:46:33 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/14 22:14:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*brloop(char *str)
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

static int			brainfuck_firt_part(char x, unsigned char **ptr)
{
	if (x == '>')
		(*ptr)++;
	else if (x == '<')
		(*ptr)--;
	else if (x == '+')
		(**ptr)++;
	else if (x == '-')
		(**ptr)--;
	else if (x == '.')
		ft_putchar(**ptr);
	else
		return (0);
	return (1);
}

char				*ft_brainfuck(char *str, unsigned char *ptr)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (brainfuck_firt_part(*str, &ptr))
			(void)str;
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
	return (str);
}
