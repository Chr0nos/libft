/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_wrapper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:05:16 by snicolet          #+#    #+#             */
/*   Updated: 2017/11/07 00:24:27 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_WRAPPER_H
# define MALLOC_WRAPPER_H

void	*malloc(size_t size);
void	free(void *ptr);
void	*ft_realloc(void *ptr, size_t size);

#endif
