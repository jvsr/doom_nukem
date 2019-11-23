/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_sidedefs.c                               :+:    :+:            */
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

#define SIDEDEF_SIZE 30

// static void	print_sidedef(t_wad_sidedef *sidedef)
// {
// 	ft_printf("X OFF:\t%d\nY OFF:\t%d\nT UP:\t%s\nT DWN:\t%s\nT MID:\t%s\nSEC:\t%d\n",
// 		sidedef->offset_x,
// 		sidedef->offset_y,
// 		sidedef->texture_up,
// 		sidedef->texture_low,
// 		sidedef->texture_mid,
// 		sidedef->sector);
// }

static void	alloc_sidedefs(t_wad_level *level, size_t sidedefs_amount)
{
	size_t	i;

	level->sidedefs_amount = sidedefs_amount;
	level->sidedefs = (t_wad_sidedef**)ft_memalloc(sizeof(t_wad_sidedef*) * sidedefs_amount);
	if (level->sidedefs == NULL)
		error_msg_errno("Failed to alloc level sidedefs");
	i = 0;
	while (i < sidedefs_amount)
	{
		level->sidedefs[i] = (t_wad_sidedef*)ft_memalloc(sizeof(t_wad_sidedef));
		if (level->sidedefs[i] == NULL)
			error_msg_errno("Failed to alloc level sidedef");
		level->sidedefs[i]->texture_up = ft_strnew(8);
		if (level->sidedefs[i]->texture_up == NULL)
			error_msg_errno("Failed to alloc level sidedef up");
		level->sidedefs[i]->texture_low = ft_strnew(8);
		if (level->sidedefs[i]->texture_low == NULL)
			error_msg_errno("Failed to alloc level sidedef low");
		level->sidedefs[i]->texture_mid = ft_strnew(8);
		if (level->sidedefs[i]->texture_mid == NULL)
			error_msg_errno("Failed to alloc level sidedef mid");
		i++;
	}
}

static void				fill_wad_sidedef(t_binary_read *wad_bin, t_wad_sidedef *sidedef)
{
	long	name;

	sidedef->offset_x = read_short(wad_bin);
	sidedef->offset_y = read_short(wad_bin);
	name = read_long(wad_bin);
	ft_memcpy(sidedef->texture_up, &name, 8);
	name = read_long(wad_bin);
	ft_memcpy(sidedef->texture_low, &name, 8);
	name = read_long(wad_bin);
	ft_memcpy(sidedef->texture_mid, &name, 8);
	sidedef->sector = read_short(wad_bin);
}

void	parse_wad_sidedefs(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;
	(void)wad_bin;
	(void)directory;

	if (directory->size_lump % SIDEDEF_SIZE == 0)
		alloc_sidedefs(level, directory->size_lump / SIDEDEF_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid sidedefs lump");
	i = 0;
	while (i < level->sidedefs_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * SIDEDEF_SIZE;
		fill_wad_sidedef(wad_bin, level->sidedefs[i]);
		// print_sidedef(level->sidedefs[i]);
		i++;
	}
}