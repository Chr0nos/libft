/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:44:42 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/31 12:47:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int             ft_gl(char *dst, const int fd, const size_t dest_size)
{
    static char		buff[0xF000 + 1];
    static char		*ptr = buff;
    char			*nl;
    ssize_t			r;

    r = 0;
    if ((long)ptr == 0x1l)
        ptr = buff;
    if (!(nl = ft_strchr(ptr, '\n')))
    {
        if (ptr != buff)
        {
            ft_strcpy(buff, ptr);
            ptr = buff + ((ssize_t)sizeof(buff) -
				((ssize_t)ptr - (ssize_t)buff)) - 1;
        }
        r = read(fd, ptr, sizeof(buff) - ((size_t)ptr - (size_t)buff) - 1);
        ptr[r] = '\0';
        ptr = buff;
    }
    if ((nl = ft_strchr(ptr, '\n')))
        (void)ft_memcpy(dst, ptr, FT_MIN((size_t)nl - (size_t)ptr, dest_size -
			1)), dst[FT_MIN((size_t)nl - (size_t)ptr, dest_size - 1)] = 0;
    ptr = nl + 1;
    return (!!nl);
}
