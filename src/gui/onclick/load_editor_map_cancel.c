/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_editor_map_cancel.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 14:52:40 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/13 14:54:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map_editor.h"
#include "eventstate.h"
#include "game.h"
#include "gui.h"

void			load_editor_map_cancel(t_game *game, t_transform *gui)
{
	t_transform	*load_ui;

	(void)gui;
	load_ui = get_gui_child(game->ui, "mapEditorSelectLoadMenu");
	set_elem_show_clickable(load_ui, FALSE);
}
