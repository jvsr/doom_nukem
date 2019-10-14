/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_list_gen.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:21:41 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 17:21:41 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "serializer.h"

t_list	*read_list_gen(unsigned char *header, unsigned char *bytes,
						size_t *header_pos, size_t d_size)
{
	long	loc;
	long	size;
	t_list	*list;

	loc = read_long(header + *header_pos);
	*header_pos += 8;
	size = read_long(header + *header_pos);
	*header_pos += 8;
	list = ft_lstnew(ft_memalloc(d_size), d_size);
	ft_memcpy(list->content, bytes, d_size);
	if (size != (long)d_size)
		ft_lstaddbck(&list,
			read_list_gen(header, bytes + d_size, header_pos, d_size));
	else
		list->next = NULL;
	return (list);
}
