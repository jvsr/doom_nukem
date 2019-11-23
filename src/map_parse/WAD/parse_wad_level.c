/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_level.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 19:03:22 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 21:45:12 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define LEVEL_DIR_SIZE 10

static void	get_next_directory(t_binary_read *wad_bin, t_wad_directory **directory)
{
	*directory = read_wad_directory(wad_bin);
}

void	parse_wad_level(t_binary_read *wad_bin, t_wad *wad, t_wad_directory *directory)
{
	size_t			i;
	t_wad_level		*level;
	size_t const	dir_loc = wad_bin->content_pos;

	level = ft_memalloc(sizeof(t_wad_level));
	if (level == NULL)
		error_msg_errno("Failed to alloc wad level");
	i = 0;
	while (i < LEVEL_DIR_SIZE)
	{
		wad_bin->content_pos = dir_loc + i * 16;
		get_next_directory(wad_bin, &directory);
		if (ft_strequ(directory->name_lump, "THINGS"))
			parse_wad_things(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "LINEDEFS"))
			parse_wad_linedefs(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "SIDEDEFS"))
			parse_wad_sidedefs(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "VERTEXES"))
			parse_wad_vertexes(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "SEGS"))
			parse_wad_segs(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "SSECTORS"))
			parse_wad_ssectors(wad_bin, level, directory);
		else
			print_directory(directory);
		i++;
	}
	wad->levels = level;
}
