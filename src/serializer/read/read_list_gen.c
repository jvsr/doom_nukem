/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_list_gen.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:21:41 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:54:16 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

t_list	*read_list_gen(t_binary_read *bin_r, t_uint64 d_size)
{
	t_uint64	size;
	t_list		*list;

	bin_r->header_pos += sizeof(t_uint64);
	size = read_header(bin_r);
	list = ft_lstnew(ft_memalloc(d_size), d_size);
	if (list == NULL)
		error_msg_errno("Unable To allocate list");
	ft_memcpy(list->content, bin_r->bytes + bin_r->content_pos, d_size);
	bin_r->content_pos += d_size;
	if (bin_r->endian != detect_endian())
		swap_bytes(list->content, d_size);
	if (size != d_size)
		ft_lstaddbck(&list, read_list_gen(bin_r, d_size));
	else
		list->next = NULL;
	return (list);
}
