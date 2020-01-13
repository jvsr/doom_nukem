/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_nodes.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 18:21:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define NODE_SIZE 28

// static void	print_node(t_wad_node *node)
// {
// 	ft_printf("PL X:\t%hu\nPL Y:\t%hu\nCPL X:\t%hu\nCPL Y:\t%hu\nR BOX:\t%ld\nL BOX:\t%ld\nR CHLD:\t%hu\nL CHLD:\t%hu\n\n",
// 		node->partition_line_x,
// 		node->partition_line_y,
// 		node->change_partition_line_x,
// 		node->change_partition_line_y,
// 		node->right_box,
// 		node->left_box,
// 		node->right_child,
// 		node->left_child);
// }

static void	alloc_nodes(t_wad_level *level, size_t nodes_amount)
{
	size_t	i;

	level->nodes_amount = nodes_amount;
	level->nodes = (t_wad_node**)ft_memalloc(sizeof(t_wad_node*) * nodes_amount);
	if (level->nodes == NULL)
		error_msg_errno("Failed to alloc level nodes");
	i = 0;
	while (i < nodes_amount)
	{
		level->nodes[i] = (t_wad_node*)ft_memalloc(sizeof(t_wad_node));
		if (level->nodes[i] == NULL)
			error_msg_errno("Failed to alloc level node");
		i++;
	}
}

static void	fill_wad_node(t_binary_read *wad_bin, t_wad_node *node)
{
	node->partition_line_x = read_short(wad_bin);
	node->partition_line_y = read_short(wad_bin);
	node->change_partition_line_x = read_short(wad_bin);
	node->change_partition_line_y = read_short(wad_bin);
	node->right_box = read_long(wad_bin);
	node->left_box = read_long(wad_bin);
	node->right_child = read_short(wad_bin);
	node->left_child = read_short(wad_bin);
}

void		parse_wad_nodes(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	size_t	i;

	(void)wad_bin;
	(void)directory;
	if (directory->size_lump % NODE_SIZE == 0)
		alloc_nodes(level, directory->size_lump / NODE_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid nodes lump");
	i = 0;
	while (i < level->nodes_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * NODE_SIZE;
		fill_wad_node(wad_bin, level->nodes[i]);
		// print_node(level->nodes[i]);
		i++;
	}
}
