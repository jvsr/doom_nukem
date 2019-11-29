/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_linedefs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/29 14:57:12 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define LINEDEF_SIZE 14

// static void	print_linedef(t_wad_linedef *linedef)
// {
// 	ft_printf("V BEG:\t%hu\nV END:\t%hu\nFLG:\t%d\nL TYP:\t%d\nS TAG:\t%d\nSD RGT:\t%d\nSD LFT:\t%d\n\n",
// 		linedef->vertex_begin,
// 		linedef->vertex_end,
// 		linedef->flags,
// 		linedef->line_type,
// 		linedef->sector_tag,
// 		linedef->sidedef_right,
// 		linedef->sidedef_left);
// }

static void	alloc_linedefs(t_wad_level *level, size_t linedefs_amount)
{
	size_t	i;

	level->linedefs_amount = linedefs_amount;
	level->linedefs = (t_wad_linedef**)ft_memalloc(sizeof(t_wad_linedef*) * linedefs_amount);
	if (level->linedefs == NULL)
		error_msg_errno("Failed to alloc level linedefs");
	i = 0;
	while (i < linedefs_amount)
	{
		level->linedefs[i] = (t_wad_linedef*)ft_memalloc(sizeof(t_wad_linedef));
		if (level->linedefs[i] == NULL)
			error_msg_errno("Failed to alloc level linedef");
		i++;
	}
}

static void				fill_wad_linedef(t_binary_read *wad_bin, t_wad_linedef *linedef)
{
	linedef->vertex_begin = read_short(wad_bin);
	linedef->vertex_end = read_short(wad_bin);
	linedef->flags = read_short(wad_bin);
	linedef->line_type = read_short(wad_bin);
	linedef->sector_tag = read_short(wad_bin);
	linedef->sidedef_right = read_short(wad_bin);
	linedef->sidedef_left = read_short(wad_bin);
}

void	parse_wad_linedefs(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;
	(void)wad_bin;
	(void)directory;

	if (directory->size_lump % LINEDEF_SIZE == 0)
		alloc_linedefs(level, directory->size_lump / LINEDEF_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid linedefs lump");
	i = 0;
	while (i < level->linedefs_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * LINEDEF_SIZE;
		fill_wad_linedef(wad_bin, level->linedefs[i]);
		// print_linedef(level->linedefs[i]);
		i++;
	}
}