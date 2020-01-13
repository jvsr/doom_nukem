/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_segs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 18:43:38 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define SEG_SIZE 12

// static void	print_seg(t_wad_seg *seg)
// {
// 	ft_printf("V BEG:\t%d\nV END:\t%d\nANG:\t%hx\nLDEF:\t%d\nDIR:\t%d\nOFF:\t%d\n\n",
// 		seg->vertex_begin,
// 		seg->vertex_end,
// 		seg->angle,
// 		seg->linedef_no,
// 		seg->direction,
// 		seg->offset);
// }

static void	alloc_segs(t_wad_level *level, size_t segs_amount)
{
	size_t	i;

	level->segs_amount = segs_amount;
	level->segs = (t_wad_seg**)ft_memalloc(sizeof(t_wad_seg*) * segs_amount);
	if (level->segs == NULL)
		error_msg_errno("Failed to alloc level segs");
	i = 0;
	while (i < segs_amount)
	{
		level->segs[i] = (t_wad_seg*)ft_memalloc(sizeof(t_wad_seg));
		if (level->segs[i] == NULL)
			error_msg_errno("Failed to alloc level seg");
		i++;
	}
}

static void	fill_wad_seg(t_binary_read *wad_bin, t_wad_seg *seg)
{
	seg->vertex_begin = read_short(wad_bin);
	seg->vertex_end = read_short(wad_bin);
	seg->angle = read_short(wad_bin);
	seg->linedef_no = read_short(wad_bin);
	seg->direction = read_short(wad_bin);
	seg->offset = read_short(wad_bin);
}

void		parse_wad_segs(t_binary_read *wad_bin,
				t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;

	(void)wad_bin;
	(void)directory;
	if (directory->size_lump % SEG_SIZE == 0)
		alloc_segs(level, directory->size_lump / SEG_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid segs lump");
	i = 0;
	while (i < level->segs_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * SEG_SIZE;
		fill_wad_seg(wad_bin, level->segs[i]);
		// print_seg(level->segs[i]);
		i++;
	}
}
