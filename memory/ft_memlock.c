/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:14:55 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/09 02:18:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
** i know what you are asking to you: "what is he doing here ? why not a global"
** the anwser is short: the norminette
** at 42 we have coding rules that prevent me to use a global in the header
** because it's not const so i have to have a singletone like that...
*/

pthread_mutex_t		*ft_memlock(void)
{
	static pthread_mutex_t		lock = PTHREAD_MUTEX_INITIALIZER;

	return (&lock);
}
