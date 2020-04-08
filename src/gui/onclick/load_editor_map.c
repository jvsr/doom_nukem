/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_editor_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 16:53:05 by euan          #+#    #+#                 */
/*   Updated: 2020/04/08 17:40:12 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_str.h"
#include "serializer.h"
#include "map_editor.h"
#include "renderer.h"
#include "onclick.h"
#include "error.h"
#include "game.h"
#include "gui.h"

void		create_map(t_game *game, char *name)
{
	char			*loc;
	t_map			*map;
	t_editor_map	*emap;

	loc = ft_strformat("%s/%s", SAVE_LOCATION, name);
	if (loc == NULL)
		error_msg_errno("Failed to allocate file name");
	ft_strdel(&name);
	map = read_map_struct(loc, game->exec_path);
	if (map == NULL)
		error_msg_errno("Invalid Map Location or Allocation Error");
	emap = map_editor_rev_convert(map);
	delete_map(&map);
	ft_strdel(&loc);
	game->editor_map = emap;
}

void		load_editor_map(t_game *game, t_transform *gui)
{
	t_list		*maps;
	t_transform	*load_ui;
	t_transform	*select_map;

	(void)gui;
	load_ui = get_gui_child(game->ui, "mapEditorSelectLoadMenu");
	select_map = get_gui_child(game->ui, "mapEditorSelectLoadText");
	set_elem_show_clickable(load_ui, TRUE);
	create_map_list(game, CUSTOM_PATH);
    maps = read_map_list();
	if (maps != NULL)
		set_elem_text_str(select_map, maps->content);
    ft_lstdel(&maps, ft_lstdelmem);
}
