/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:27:39 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/31 14:55:18 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "setting.h"
#include "onclick.h"
#include "eventstate.h"
#include "serializer.h"

void	remove_options(t_game *game)
{
	t_transform	*menu;
	t_transform	*overlay;

	menu = get_gui_child(game->ui, "optionsmenu");
	overlay = get_gui_child(game->ui, "optionsoverlay");
	set_elem_show_clickable(menu, FALSE);
	set_elem_show_clickable(overlay, FALSE);
}

void	options_return(t_game *game, t_transform *gui)
{
	(void)gui;
	if (game->setting->changed == TRUE || game->setting->confirm == TRUE)
	{
		write_settings(game->setting);
		if (game->setting->confirm == TRUE)
		{
			add_confirmation(game);
			game->cureventstate->eventstate = options_confirmation;
		}
	}
	if (game->setting->confirm == FALSE)
		remove_options(game);
	game->setting->changed = FALSE;
	game->setting->confirm = FALSE;
}

void	options_open_controls(t_game *game, t_transform *gui)
{
	t_gui			*ui;
	t_transform		*elem;
	const t_control	control = game->setting->controls;

	(void)gui;
	ui = game->ui;
	elem = get_gui_child(ui, "controlsmenu");
	set_elem_show_clickable(elem, TRUE);
	elem = get_gui_child(ui, "controlsmenu");
	set_elem_show_clickable(elem, TRUE);
	set_key_str(control.forward, get_gui_child(ui, "controlsforwardbutton"));
	set_key_str(control.backward, get_gui_child(ui, "controlsbackwardbutton"));
	set_key_str(control.left, get_gui_child(ui, "controlsleftbutton"));
	set_key_str(control.right, get_gui_child(ui, "controlsrightbutton"));
	set_key_str(control.interact, get_gui_child(ui, "controlsinteractbutton"));
	set_key_str(control.shoot, get_gui_child(ui, "controlsshootbutton"));
	set_key_str(control.crouch, get_gui_child(ui, "controlscrouchbutton"));
	set_key_str(control.jump, get_gui_child(ui, "controlsjumpbutton"));
	game->cureventstate->eventstate = controls;
}
