/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_wad_header.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:00:49 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/18 19:13:06 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "wad.h"
#include "serializer.h"
#include "error.h"

#include <stdio.h>
static t_wad_type	get_wad_header_type(int i)
{
	t_wad_type	type;

	if (ft_memequ((void*)&i, (void*)"IWAD", 4))
		type = IWAD;
	else if (ft_memequ((void*)&i, (void*)"PWAD", 4))
		type = PWAD;
	else
		type = -1;
	return (type);
}

t_wad_header		*read_wad_header(t_binary_read *bin_r)
{
	t_wad_header	*wad_header;

	wad_header = (t_wad_header*)ft_memalloc(sizeof(t_wad_header));
	if (wad_header == NULL)
		error_msg_errno("Failed to alloc wad_header");
	wad_header->type = get_wad_header_type(read_int(bin_r));
	wad_header->no_entries = read_int(bin_r);
	wad_header->loc_directory = read_int(bin_r);
	return (wad_header);
}
