/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_blockmap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/24 22:07:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

static void	print_blockmap(t_wad_blockmap *blockmap)
{
	ft_printf("G ORG X:\t%hu\nG ORG Y:\t%hu\nCOL:\t%d\nROW:\t%d\n\n",
		blockmap->grid_org_x,
		blockmap->grid_org_y,
		blockmap->colums_no,
		blockmap->rows_no);
}

static void	alloc_blockmap(t_wad_level *level)
{
	level->blockmap = (t_wad_blockmap*)ft_memalloc(sizeof(t_wad_blockmap));
	if (level->blockmap == NULL)
		error_msg_errno("Failed to alloc level blockmap");
}

// static void				fill_wad_blockmap(t_binary_read *wad_bin, t_wad_blockmap *blockmap)
// {
// 	blockmap->vertex_begin = read_short(wad_bin);
// 	blockmap->vertex_end = read_short(wad_bin);
// 	blockmap->flags = read_short(wad_bin);
// 	blockmap->line_type = read_short(wad_bin);
// 	blockmap->sector_tag = read_short(wad_bin);
// 	blockmap->sidedef_right = read_short(wad_bin);
// 	blockmap->sidedef_left = read_short(wad_bin);
// }

void	read_blockmap_header(t_binary_read *wad_bin, t_wad_blockmap *blockmap)
{
	blockmap->grid_org_x = read_short(wad_bin);
	blockmap->grid_org_y = read_short(wad_bin);
	blockmap->colums_no = read_short(wad_bin);
	blockmap->rows_no = read_short(wad_bin);
}

void	read_blockmap_offsets(t_binary_read *wad_bin, t_wad_blockmap *blockmap)
{
	size_t	i;

	i = 0;
	while (i < (size_t)(blockmap->rows_no * blockmap->colums_no))
	{
		blockmap->offsets[i] = read_short(wad_bin);
		i++;
	}
}

void	parse_wad_blockmap(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	// size_t	i;
	(void)wad_bin;

	alloc_blockmap(level);
	wad_bin->content_pos = directory->loc_lump;
	read_blockmap_header(wad_bin, level->blockmap);
	level->blockmap->offsets = (short*)ft_memalloc(sizeof(short) * level->blockmap->rows_no * level->blockmap->colums_no);
	if (level->blockmap->offsets == NULL)
		error_msg_errno("Failed to alloc level blockmap offsets");
	read_blockmap_offsets(wad_bin, level->blockmap);

		print_blockmap(level->blockmap);
}