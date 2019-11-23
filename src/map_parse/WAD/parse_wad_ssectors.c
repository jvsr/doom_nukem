/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_ssectors.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 21:45:36 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define SSECTOR_SIZE 4

// static void	print_ssector(t_wad_ssector *ssector)
// {
// 	ft_printf("S NO:\t%d\nS FST:\t%d\n\n",
// 		ssector->segment_no,
// 		ssector->segment_first);
// }

static void	alloc_ssectors(t_wad_level *level, size_t ssectors_amount)
{
	size_t	i;

	level->ssectors_amount = ssectors_amount;
	level->ssectors = (t_wad_ssector**)ft_memalloc(sizeof(t_wad_ssector*) * ssectors_amount);
	if (level->ssectors == NULL)
		error_msg_errno("Failed to alloc level ssectors");
	i = 0;
	while (i < ssectors_amount)
	{
		level->ssectors[i] = (t_wad_ssector*)ft_memalloc(sizeof(t_wad_ssector));
		if (level->ssectors[i] == NULL)
			error_msg_errno("Failed to alloc level ssector");
		i++;
	}
}

static void				fill_wad_ssector(t_binary_read *wad_bin, t_wad_ssector *ssector)
{
	ssector->segment_no = read_short(wad_bin);
	ssector->segment_first = read_short(wad_bin);
}

void	parse_wad_ssectors(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;

	if (directory->size_lump % SSECTOR_SIZE == 0)
		alloc_ssectors(level, directory->size_lump / SSECTOR_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid ssectors lump");
	i = 0;
	while (i < level->ssectors_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * SSECTOR_SIZE;
		fill_wad_ssector(wad_bin, level->ssectors[i]);
		// print_ssector(level->ssectors[i]);
		i++;
	}
}
