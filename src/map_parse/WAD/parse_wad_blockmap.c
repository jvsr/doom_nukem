/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_blockmap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/25 15:04:24 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

// static void	print_blockmap(t_wad_blockmap *blockmap)
// {
// 	ft_printf("G ORG X:\t%hu\nG ORG Y:\t%hu\nCOL:\t%d\nROW:\t%d\n\n",
// 		blockmap->grid_org_x,
// 		blockmap->grid_org_y,
// 		blockmap->colums_no,
// 		blockmap->rows_no);
// }

static void	alloc_blockmap(t_wad_level *level)
{
	level->blockmap = (t_wad_blockmap*)ft_memalloc(sizeof(t_wad_blockmap));
	if (level->blockmap == NULL)
		error_msg_errno("Failed to alloc level blockmap");
}

void	read_blockmap_header(t_binary_read *wad_bin, t_wad_blockmap *blockmap)
{
	blockmap->grid_org_x = read_short(wad_bin);
	blockmap->grid_org_y = read_short(wad_bin);
	blockmap->colums_no = read_short(wad_bin);
	blockmap->rows_no = read_short(wad_bin);
}

void	read_blockmap_offset(t_binary_read *wad_bin, t_wad_blockmap *blockmap)
{
	size_t	i;

	i = 0;
	while (i < (size_t)(blockmap->rows_no * blockmap->colums_no))
	{
		blockmap->offset[i] = read_short(wad_bin);
		i++;
	}
}

int	get_blocklist_size(t_binary_read *wad_bin)
{
	unsigned short	s;
	size_t			i;

	i = 0;
	s = read_short(wad_bin);
	if (s == 0x0000)
	{
		while (s != 0xFFFF)
		{
			s = read_short(wad_bin);
			i++;
		}
	}
	else
		error_msg("Failed to parse WAD map", 25, "Invalid blocklist");
	return (i - 1);
}

void	fill_blockmap_blocklist(t_binary_read *wad_bin, short *blocklist)
{
	unsigned short	s;
	size_t			i;

	i = 0;
	s = read_short(wad_bin);
	if (s == 0x0000)
	{
		while (s != 0xFFFF)
		{
			s = read_short(wad_bin);
			if (s != 0xFFFF)
			{
				blocklist[i] = s;
				// ft_printf("linedef %d: %hu\n", i, blocklist[i]);
			}
			i++;
		}
	}
	else
		error_msg("Failed to parse WAD map", 25, "Invalid blocklist");
}

void	parse_wad_blockmap(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;
	size_t	size;

	alloc_blockmap(level);
	wad_bin->content_pos = directory->loc_lump;
	read_blockmap_header(wad_bin, level->blockmap);
	level->blockmap->offset = (short*)ft_memalloc(sizeof(short) * level->blockmap->rows_no * level->blockmap->colums_no);
	if (level->blockmap->offset == NULL)
		error_msg_errno("Failed to alloc level blockmap offset");
	level->blockmap->blocklist = (short**)ft_memalloc(sizeof(short*) * level->blockmap->rows_no * level->blockmap->colums_no);
	if (level->blockmap->blocklist == NULL)
		error_msg_errno("Failed to alloc level blockmap offset");
	read_blockmap_offset(wad_bin, level->blockmap);

	// ft_printf("BLOCKMAP SIZE: %d\n", directory->size_lump);
	i = 0;
	while (i < (size_t)(level->blockmap->rows_no * level->blockmap->colums_no))
	{
		// ft_printf(" OFFSET: %d\n", level->blockmap->offset[i]);
		wad_bin->content_pos = directory->loc_lump + level->blockmap->offset[i] * 2;
		size = get_blocklist_size(wad_bin);
		if (size > 0)
			level->blockmap->blocklist[i] = (short*)ft_memalloc(sizeof(short) * size);
		wad_bin->content_pos = directory->loc_lump + level->blockmap->offset[i] * 2;
		fill_blockmap_blocklist(wad_bin, level->blockmap->blocklist[i]);
		i++;
	}
	// print_blockmap(level->blockmap);
}