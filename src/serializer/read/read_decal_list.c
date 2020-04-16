/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_decal_list.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 21:25:22 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:54:38 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "serializer.h"
#include "rinfo.h"
#include "error.h"

t_list		*read_decal_list(t_binary_read *bin_r)
{
	t_uint64	size;
	t_list		*list;
	t_decal		decal;

	bin_r->header_pos += sizeof(t_uint64);
	size = read_header(bin_r);
	decal = read_decal(bin_r);
	list = ft_lstnew_dup(&decal, sizeof(t_decal));
	if (list == NULL)
		error_msg_errno("Unable To allocate list");
	if (size != sizeof(t_decal))
		ft_lstaddbck(&list, read_decal_list(bin_r));
	return (list);
}
