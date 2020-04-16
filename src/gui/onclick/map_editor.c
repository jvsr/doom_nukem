/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 15:57:57 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/13 15:12:53 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_num.h"

#include "gui.h"
#include "game.h"
#include "types.h"
#include "textures.h"
#include "eventstate.h"
#include "map_editor.h"
#include "error.h"

void			map_editor_add_confirmation(t_game *game)
{
	t_transform	*menu;

	menu = get_gui_child(game->ui, "mapEditorConfirmationMenu");
	set_elem_show_clickable(menu, TRUE);
}

void			map_editor_remove_confirmation(t_game *game)
{
	t_transform	*menu;

	menu = get_gui_child(game->ui, "mapEditorConfirmationMenu");
	set_elem_show_clickable(menu, FALSE);
}

void			map_editor_confirmation_return(t_game *game, t_transform *gui)
{
	t_transform	*map_editor_elem;

	(void)gui;
	map_editor_remove_confirmation(game);
	set_elem_show_clickable(get_gui_child(game->ui, "mapEditor"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainMenu"), TRUE);
	map_editor_elem = get_gui_child(game->ui, "mapEditorView");
	map_editor_del(&game->editor_map);
	map_editor_elem->gui_elem.map_editor->show_last_click = FALSE;
	set_elem_redraw(map_editor_elem);
	game->cureventstate->eventstate = mainmenu;
}
