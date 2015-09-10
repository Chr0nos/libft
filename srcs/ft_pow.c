/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 10:08:09 by snicolet          #+#    #+#             */
/*   Updated: 2015/08/17 19:30:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int power)
{
	int		result;

	if (nb < 0)
		nb *= -1;
	if (power == 0)
		return (1);
	if ((power < 0) || (nb == 0))
		return (0);
	result = 1;
	while (power--)
		result *= nb;
	return (result);
}
