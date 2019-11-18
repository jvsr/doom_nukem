/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   editor_select.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:17:33 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/14 12:19:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "eventstate.h"

void	map_editor_select_return(t_game *game, t_transform *gui)
{
	(void)gui;
	set_elem_show_clickable(get_gui_child(game->ui, "mapeditorselect"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainmenu"), TRUE);
	game->cureventstate->eventstate = mainmenu;
}
