/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_sectors.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 18:21:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_mem.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define SECTOR_SIZE 26

// static void	print_sector(t_wad_sector *sector)
// {
// 	ft_printf("H FLR:\t%hu\nH CEI:\t%hu\nTEX F:\t%s\nTEX C:\t%s\nLL:\t%hd\nSEC S:\t%d\nS TAG:\t%u\n\n",
// 		sector->height_floor,
// 		sector->height_ceiling,
// 		sector->texture_floor,
// 		sector->texture_ceiling,
// 		sector->light_level,
// 		sector->sector_special,
// 		sector->sector_tag);
// }

static void	alloc_sectors(t_wad_level *level, size_t sectors_amount)
{
	size_t	i;

	level->sectors_amount = sectors_amount;
	level->sectors = (t_wad_sector**)ft_memalloc(sizeof(t_wad_sector*) * sectors_amount);
	if (level->sectors == NULL)
		error_msg_errno("Failed to alloc level sectors");
	i = 0;
	while (i < sectors_amount)
	{
		level->sectors[i] = (t_wad_sector*)ft_memalloc(sizeof(t_wad_sector));
		if (level->sectors[i] == NULL)
			error_msg_errno("Failed to alloc level sector");
		level->sectors[i]->texture_floor = ft_strnew(8);
		if (level->sectors[i]->texture_floor == NULL)
			error_msg_errno("Failed to alloc level sector texture floor");
		level->sectors[i]->texture_ceiling = ft_strnew(8);
		if (level->sectors[i]->texture_ceiling == NULL)
			error_msg_errno("Failed to alloc level sector texture ceiling");
		i++;
	}
}

static void				fill_wad_sector(t_binary_read *wad_bin, t_wad_sector *sector)
{
	long	name;

	sector->height_floor = read_short(wad_bin);
	sector->height_ceiling = read_short(wad_bin);
	name = read_long(wad_bin);
	ft_memcpy(sector->texture_floor, &name, 8);
	name = read_long(wad_bin);
	ft_memcpy(sector->texture_ceiling, &name, 8);
	sector->light_level = read_short(wad_bin) / 8;
	sector->sector_special = read_short(wad_bin);
	sector->sector_tag = read_short(wad_bin);
}

void	parse_wad_sectors(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;
	(void)wad_bin;
	(void)directory;

	if (directory->size_lump % SECTOR_SIZE == 0)
		alloc_sectors(level, directory->size_lump / SECTOR_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid sectors lump");
	i = 0;
	while (i < level->sectors_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * SECTOR_SIZE;
		fill_wad_sector(wad_bin, level->sectors[i]);
		// print_sector(level->sectors[i]);
		i++;
	}
}