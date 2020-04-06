/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   editor_select.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:17:33 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:14:29 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "eventstate.h"

void	map_editor_select_return(t_game *game, t_transform *gui)
{
	(void)gui;
	set_elem_show_clickable(get_gui_child(game->ui, "mapEditorSelect"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainMenu"), TRUE);
	game->cureventstate->eventstate = mainmenu;
}
