/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 22:10:12 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 15:50:36 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "eventstate.h"
#include "serializer.h"

void	controls_return(t_game *game, t_transform *gui)
{
	t_transform	*menu;
	t_transform	*overlay;

	(void)gui;
	write_settings(game->setting);
	menu = get_gui_child(game->ui, "controlsmenu");
	overlay = get_gui_child(game->ui, "controlsoverlay");
	set_elem_show_clickable(menu, FALSE);
	set_elem_show_clickable(overlay, FALSE);
}
