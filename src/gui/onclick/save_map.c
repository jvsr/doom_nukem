/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 13:35:31 by euan          #+#    #+#                 */
/*   Updated: 2020/04/08 16:01:59 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "map_editor.h"
#include "serializer.h"
#include "rinfo.h"
#include "game.h"
#include "gui.h"
#include "error.h"
#include "renderer.h"

static t_editor_map	*dup_map(t_editor_map *emap)
{
	t_editor_map	*new;

	new = map_editor_new();
	new->walls = ft_lstdup_dup(emap->walls);
	if (emap->walls != NULL && new->walls == NULL)
		error_msg_errno("Failed to duplicate editor map walls");
	new->objects = ft_lstdup_dup(emap->objects);
	if (emap->objects != NULL && new->objects == NULL)
		error_msg_errno("Failed to duplicate editor map objects");
	new->has_skybox = emap->has_skybox;
	new->skybox = emap->skybox;
	return (new);
}

void		save_map(t_game *game, t_transform *gui)
{
	t_map			*map;
	t_editor_map	*dup;

	(void)gui;
	map = NULL;
	dup = dup_map(game->editor_map);
	if (ft_lstlen(game->editor_map->walls) < 3)
		return ((void)ft_printf("Map Does Not Contain Enough Walls\n"));
	map_editor_clean(dup);
	map = map_editor_convert(dup);
	map_editor_del(&dup);
	delete_map(&map);
}
