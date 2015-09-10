/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 13:46:14 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/23 15:05:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		p;

	p = 0;
	while (src[p])
	{
		dest[p] = src[p];
		p++;
	}
	dest[p] = '\0';
	return (dest);
}

char	*ft_strlcpy(char *dest, char *src)
{
	int		p;

	p = 0;
	while (src[p])
	{
		dest[p] = src[p];
		p++;
	}
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
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
