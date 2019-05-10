/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:35:56 by snicolet          #+#    #+#             */
/*   Updated: 2019/05/10 10:41:17 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		dummy(struct s_printf *pf)
{
	char		buf[32];
	int			len;

	while (1)
	{
		len = ft_itobuff(buf, rand(), 16, "0123456789abcdef");
		ft_printf_append(pf, buf, len);
		ft_printf_append(pf, " ", 1);
	}
}

static void		dummy_stack(struct s_printf *pf)
{
	while (1)
		ft_printf_stack(pf, "%x ", rand());
}

int				main(void)
{
	ft_printf("%K", dummy_stack);
	return (0);
}
