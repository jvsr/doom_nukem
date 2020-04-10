/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 13:35:31 by euan          #+#    #+#                 */
/*   Updated: 2020/04/08 16:52:04 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/ft_printf.h"
#include "libft/ft_list.h"
#include "libft/ft_str.h"
#include "map_editor.h"
#include "serializer.h"
#include "onclick.h"
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

static void			write_map(t_game *game, t_map *map)
{
	size_t	i;
	char	*name;
	size_t	offset;

	i = 0;
	name = ft_strformat("%s/%s/%s_%d",
		game->exec_path, CUSTOM_PATH, SAVE_NAME, i);
	if (name == NULL)
		error_msg_errno("Failed to allocate file name");
	while (access(name, F_OK) == 0)
	{
		i++;
		ft_strdel(&name);
		name = ft_strformat("%s/%s/%s_%d",
			game->exec_path, CUSTOM_PATH, SAVE_NAME, i);
		if (name == NULL)
			error_msg_errno("Failed to allocate file name");
	}
	offset = (size_t)ft_strstr(name, SAVE_LOCATION) - (size_t)name;
	write_map_struct(map, &name[offset], game->exec_path);
	ft_printf("Map Saved! (%s)\n", &name[offset]);
	ft_strdel(&name);
}

static t_bool		find_start_end(t_editor_map *emap)
{
	t_list			*objs;
	t_editor_object	*obj;
	int				start_found;
	t_bool			end_found;

	end_found = FALSE;
	start_found = 0;
	if (ft_lstlen(emap->objects) < 2)
		return (FALSE);
	objs = emap->objects;
	while (objs)
	{
		obj = objs->content;
		if (obj->type == O_START)
			start_found++;
		if (obj->type == O_END)
			end_found = TRUE;
		objs = objs->next;
	}
	return (start_found == 1 && end_found);
}

void				save_map(t_game *game, t_transform *gui)
{
	t_map			*map;
	t_editor_map	*dup;

	(void)gui;
	map = NULL;
	if (ft_lstlen(game->editor_map->walls) < 3)
		return ((void)ft_printf("Map Does Not Contain Enough Walls\n"));
	if (find_start_end(game->editor_map) == FALSE)
		return ((void)ft_printf("Map Does Not Contain Valid Start and Ends\n"));
	dup = dup_map(game->editor_map);
	map_editor_clean(dup);
	map = map_editor_convert(dup);
	map_editor_del(&dup);
	write_map(game, map);
	delete_map(&map);
}
