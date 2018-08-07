/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:58:06 by snicolet          #+#    #+#             */
/*   Updated: 2018/08/07 17:58:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void                 ft_printf_stack_init(const t_printf *pf,
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

static void                 ft_printf_stack_end(t_printf *pf,
    const t_printf *child)
{
	pf->buff_asprintf = child->buff_asprintf;
	pf->buff_start = child->buff_start;
	pf->total_len += child->total_len;
	pf->slen += child->size;
	pf->space_left = child->space_left;
	pf->size += child->size;
	pf->raw_len += child->raw_len;
	pf->flags |= child->flags & FT_PF_QUIT;
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
