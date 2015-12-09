/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:44:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/01 02:38:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	p;

	p = 0;
	while ((src[p]) && (p < n))
	{
		dest[p] = src[p];
		p++;
	}
	while (p < n)
		dest[p++] = '\0';
	return (dest);
}
