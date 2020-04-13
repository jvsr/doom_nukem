/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_editor_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 16:53:05 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 14:52:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/ft_list.h"
#include "libft/ft_printf.h"
#include "libft/ft_str.h"
#include "serializer.h"
#include "map_editor.h"
#include "eventstate.h"
#include "renderer.h"
#include "onclick.h"
#include "error.h"
#include "game.h"
#include "gui.h"

static t_bool	create_map(t_game *game, char *name)
{
	char			*loc;
	t_map			*map;
	t_editor_map	*emap;
	size_t			offset;

	loc = ft_strformat("%s/%s/%s", game->exec_path, CUSTOM_PATH, name);
	if (loc == NULL)
		error_msg_errno("Failed to allocate file name");
	if (access(loc, F_OK) != 0)
	{
		ft_printf("File doesn't exists anymore: %s\n", loc);
		ft_strdel(&loc);
		return (FALSE);
	}
	offset = (size_t)ft_strstr(loc, SAVE_LOCATION) - (size_t)loc;
	map = read_map_struct(&loc[offset], game->exec_path);
	ft_strdel(&loc);
	if (map == NULL)
		error_msg_errno("Invalid Map Location or Allocation Error");
	emap = map_editor_rev_convert(map);
	delete_map(&map);
	game->editor_map = emap;
	return (TRUE);
}

void			load_editor_map_ok(t_game *game, t_transform *gui)
{
	t_transform	*load_ui;
	t_transform	*select_map;
	char		*map_name;

	(void)gui;
	select_map = get_gui_child(game->ui, "mapEditorSelectLoadText");
	map_name = select_map->gui_elem.text->text;
	if (ft_strisempty(map_name) == TRUE)
		return ;
	map_editor_del(&game->editor_map);
	if (create_map(game, map_name) == FALSE)
		return ;
	set_elem_show_clickable(get_gui_child(game->ui, "mapEditor"), TRUE);
	set_elem_show_clickable(get_gui_child(game->ui, "mapeditorselect"), FALSE);
	load_ui = get_gui_child(game->ui, "mapEditorSelectLoadMenu");
	set_elem_show_clickable(load_ui, FALSE);
	game->cureventstate->eventstate = map_editor;
}

void			load_editor_map_next(t_game *game, t_transform *gui)
{
	t_list		*lst;
	t_list		*maps;
	t_transform	*select_map;

	(void)gui;
	select_map = get_gui_child(game->ui, "mapEditorSelectLoadText");
	create_map_list(game, CUSTOM_PATH);
	maps = read_map_list();
	lst = maps;
	while (lst != NULL)
	{
		if (ft_strequ(lst->content, select_map->gui_elem.text->text))
		{
			lst = lst->next;
			break ;
		}
		lst = lst->next;
	}
	if (lst == NULL)
		lst = maps;
	if (lst == NULL)
		set_elem_text_str(select_map, "");
	else
		set_elem_text_str(select_map, lst->content);
	ft_lstdel(&maps, ft_lstdelmem);
}

void			load_editor_map_prv(t_game *game, t_transform *gui)
{
	t_list		*lst;
	t_list		*prv;
	t_list		*maps;
	t_transform	*select_map;

	(void)gui;
	prv = NULL;
	select_map = get_gui_child(game->ui, "mapEditorSelectLoadText");
	create_map_list(game, CUSTOM_PATH);
	maps = read_map_list();
	lst = maps;
	while (lst != NULL)
	{
		if (ft_strequ(lst->content, select_map->gui_elem.text->text))
			break ;
		prv = lst;
		lst = lst->next;
	}
	if (prv == NULL && maps != NULL)
		prv = ft_lstlast(maps);
	if (prv == NULL)
		set_elem_text_str(select_map, "");
	else
		set_elem_text_str(select_map, prv->content);
	ft_lstdel(&maps, ft_lstdelmem);
}

void			load_editor_map(t_game *game, t_transform *gui)
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
	if (maps == NULL)
		set_elem_text_str(select_map, "");
	else
		set_elem_text_str(select_map, maps->content);
	ft_lstdel(&maps, ft_lstdelmem);
}
