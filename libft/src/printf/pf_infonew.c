/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_infonew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:28:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:29:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mem.h"
#include "ft_str.h"

static t_info	*freeret(t_info **info)
{
	ft_memdel((void **)info);
	return (NULL);
}

t_info			*pf_infonew(void)
{
	t_info	*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	info->buff = ft_strnew(PF_BUFF_SIZE);
	if (info->buff == NULL)
		return (freeret(&info));
	pf_infosetdefault(info);
	info->added = 0;
	info->fd = 1;
	info->buff_len = 0;
	info->buff_list = NULL;
	return (info);
}
