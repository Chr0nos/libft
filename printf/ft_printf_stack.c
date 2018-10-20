/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:58:06 by snicolet          #+#    #+#             */
/*   Updated: 2018/10/20 15:15:49 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** setup a new children for pf, the children sepration's purpose is to prevent
** any corruption inside the parent, the children's information are limited.
** each children have it's own va_list.
** only flags in FT_PF_ALLOW will be transmited
*/

static void					ft_printf_stack_init(const t_printf *pf,
	t_printf *child, va_list *ap)
{
	ft_bzero(child, sizeof(*child));
	child->ap = ap;
	child->buffer = pf->buffer;
	child->buff_asprintf = pf->buff_asprintf;
	child->buff_start = &pf->buffer[pf->size];
	child->flags = pf->flags & FT_PF_ALLOW;
	child->space_left = pf->space_left;
	child->buffer_maxsize = pf->buffer_maxsize;
	child->fd = pf->fd;
}

/*
** this function put some steps information to the parent t_printf, like
** the new position in the buffer,
** it is very important to call it at the end of a stacking of printf calls,
** there is only one flag allowd to be push to the parent: FT_PF_ERROR,
** if you need to transmit any data to the parent, use pf->raw_value, this one
** will be peacefully given to parent.
*/

static void					ft_printf_stack_end(t_printf *pf,
	const t_printf *child)
{
	pf->buff_asprintf = child->buff_asprintf;
	pf->buff_start = child->buff_start;
	pf->total_len += child->total_len;
	pf->slen += child->size;
	pf->space_left = child->space_left;
	pf->size += child->size;
	pf->raw_len += child->raw_len;
	pf->flags |= child->flags & (FT_PF_QUIT | FT_PF_ERROR);
	pf->raw_value = child->raw_value;
}

/*
** this if probably the most complicated function of this printf implementation
** this function's purpose is to be called INSIDE a previous call of printf,
** like ft_printf, ft_snprintf etc, in a normal case this is called inside a
** callback function of printf (%k or %K)
** this one make a new sub t_printf environement and re-run a ft_printf_engine
** then the revelant informations are sent to the original structure.
** the big idea here is to prevent a maximum of "write" syscalls, and prevent
** too many stack usage (each ft_printf call causes a FT_PF_BSIZE buf in the
** stack, this is not acceptable for many calls inside a callback function)
** does not send NULL for pf (SEGFAULT)
*/

int							ft_printf_stack(t_printf *pf,
	const char *format, ...)
{
	va_list				ap;
	t_printf			sub_pf;

	va_start(ap, format);
	ft_printf_stack_init(pf, &sub_pf, &ap);
	ft_printf_engine(format, &sub_pf);
	va_end(ap);
	ft_printf_stack_end(pf, &sub_pf);
	return ((int)sub_pf.size);
}
