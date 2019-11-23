/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_things.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 14:59:07 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 16:51:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define THING_SIZE 10

// static void	print_thing(t_wad_thing *thing)
// {
// 	ft_printf("X:\t%d\nY:\t%d\nANG:\t%d\nTYP:\t%d\n",
// 		thing->x_pos,
// 		thing->y_pos,
// 		thing->angle,
// 		thing->types);
// }

static void	alloc_things(t_wad_level *level, size_t things_amount)
{
	size_t	i;

	level->things_amount = things_amount;
	level->things = (t_wad_thing**)ft_memalloc(sizeof(t_wad_thing*) * things_amount);
	if (level->things == NULL)
		error_msg_errno("Failed to alloc level things");
	i = 0;
	while (i < things_amount)
	{
		level->things[i] = (t_wad_thing*)ft_memalloc(sizeof(t_wad_thing));
		if (level->things[i] == NULL)
			error_msg_errno("Failed to alloc level thing");
		i++;
	}
}

static void				fill_wad_thing(t_binary_read *wad_bin, t_wad_thing *thing)
{
	thing->x_pos = read_short(wad_bin);
	thing->y_pos = read_short(wad_bin);
	thing->angle = read_short(wad_bin);
	thing->types = read_short(wad_bin);
	thing->spawn_flags = read_short(wad_bin);
}

void	parse_wad_things(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;
	(void)wad_bin;
	(void)directory;

	if (directory->size_lump % THING_SIZE == 0)
		alloc_things(level, directory->size_lump / THING_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid THINGS lump");
	i = 0;
	while (i < level->things_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * THING_SIZE;
		fill_wad_thing(wad_bin, level->things[i]);
		// print_thing(level->things[i]);
		i++;
	}
}
