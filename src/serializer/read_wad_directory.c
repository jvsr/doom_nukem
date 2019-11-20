/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_wad_directory.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 18:17:07 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/20 19:49:44 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "wad.h"
#include "serializer.h"
#include "error.h"

#define NAME_SIZE 8

t_wad_directory	*read_wad_directory(t_binary_read *bin)
{	
	long			name_lump;
	t_wad_directory	*wad_directory;

	wad_directory = (t_wad_directory*)ft_memalloc(sizeof(t_wad_directory));
	if (wad_directory == NULL)
		error_msg_errno("Failed to alloc wad_directory");
	wad_directory->loc_lump = read_int(bin);
	wad_directory->size_lump = read_int(bin);
	wad_directory->name_lump = ft_strnew(NAME_SIZE);
	if (wad_directory->name_lump == NULL)
		error_msg_errno("Failed to alloc wad_directory->name_lump");
	name_lump = read_long(bin);
	ft_memcpy(wad_directory->name_lump, &name_lump, 8);
	return (wad_directory);
}
