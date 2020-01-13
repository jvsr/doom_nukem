/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_level.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 19:03:22 by jvisser        #+#    #+#                */
/*   Updated: 2019/12/03 14:07:17 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define LEVEL_DIR_SIZE 10

static void	get_next_directory(t_binary_read *wad_bin, t_wad_directory **directory)
{
	*directory = read_wad_directory(wad_bin);
}

static void	add_to_back(t_wad_level **head, t_wad_level *level)
{
	t_wad_level	*save;

	save = *head;
	if (*head == NULL)
		*head = level;
	else
	{
		while (save->next != NULL)
			save = save->next;
		save->next = level;
	}
}

void	print_list(t_wad_level *levels)
{
	while (levels)
	{
		ft_printf("%s -> ", levels->name);
		levels = levels->next;
	}
}

void		parse_wad_level(t_binary_read *wad_bin, t_wad *wad, t_wad_directory *directory)
{
	size_t			i;
	t_wad_level		*level;
	size_t const	dir_loc = wad_bin->content_pos;

	level = ft_memalloc(sizeof(t_wad_level));
	if (level == NULL)
		error_msg_errno("Failed to alloc wad level");
	level->next = NULL;
	level->name = ft_strdup(directory->name_lump);
	if (level->name == NULL)
		error_msg_errno("Failed to alloc wad level name");
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
		else if (ft_strequ(directory->name_lump, "NODES"))
			parse_wad_nodes(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "SECTORS"))
			parse_wad_sectors(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "REJECT"))
			parse_wad_reject(wad_bin, level, directory);
		else if (ft_strequ(directory->name_lump, "BLOCKMAP"))
			parse_wad_blockmap(wad_bin, level, directory);
		// else
		// 	print_directory(directory);
		i++;
	}
	add_to_back(&wad->levels, level);
	// print_list(wad->levels);
	// ft_printf("\n");
}
