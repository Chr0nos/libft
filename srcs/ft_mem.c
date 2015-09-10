/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 12:45:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/25 12:21:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memset(char *str, char c, unsigned int n)
{
	while (n--)
		str[n] = c;
}

void	*ft_memcpy(void *dest, void *src, unsigned int size)
{
	unsigned int	p;
	unsigned char	*d;
	unsigned char	*s;

	d = dest;
	s = src;
	p = 0;
	while (p < size)
	{
		d[p] = s[p];
		p++;
	}
	return (dest);
}
