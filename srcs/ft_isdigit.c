/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:01:58 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/27 01:11:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(const char *str)
{
	while ((*str) && ((*str >= '0') && (*str <= '9')))
		str++;
	return ((*str != '\0' ? 0 : 1));
}
