/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_vertexes.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 19:49:01 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define VERTEX_SIZE 4

// static void	print_vertex(t_wad_vertex *vertex)
// {
// 	ft_printf("X:\t%d\nY:\t%d\n",
// 		vertex->x,
// 		vertex->y);
// }

static void	alloc_vertexes(t_wad_level *level, size_t vertexes_amount)
{
	size_t	i;

	level->vertexes_amount = vertexes_amount;
	level->vertexes = (t_wad_vertex**)ft_memalloc(sizeof(t_wad_vertex*) * vertexes_amount);
	if (level->vertexes == NULL)
		error_msg_errno("Failed to alloc level vertexes");
	i = 0;
	while (i < vertexes_amount)
	{
		level->vertexes[i] = (t_wad_vertex*)ft_memalloc(sizeof(t_wad_vertex));
		if (level->vertexes[i] == NULL)
			error_msg_errno("Failed to alloc level vertex");
		i++;
	}
}

static void	fill_wad_vertex(t_binary_read *wad_bin, t_wad_vertex *vertex)
{
	vertex->x = read_short(wad_bin);
	vertex->y = read_short(wad_bin);
}

void		parse_wad_vertexes(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;

	if (directory->size_lump % VERTEX_SIZE == 0)
		alloc_vertexes(level, directory->size_lump / VERTEX_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid vertexes lump");
	i = 0;
	while (i < level->vertexes_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * VERTEX_SIZE;
		fill_wad_vertex(wad_bin, level->vertexes[i]);
		// print_vertex(level->vertexes[i]);
		i++;
	}
}
