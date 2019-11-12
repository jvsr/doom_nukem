/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:27:39 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 15:49:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "setting.h"
#include "onclick.h"
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
			add_confirmation(game);
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
	const t_control	controls = game->setting->controls;

	(void)gui;
	ui = game->ui;
	elem = get_gui_child(ui, "controlsmenu");
	set_elem_show_clickable(elem, TRUE);
	elem = get_gui_child(ui, "controlsmenu");
	set_elem_show_clickable(elem, TRUE);
	set_key_str(controls.forward, get_gui_child(ui, "controlsforwardbutton"));
	set_key_str(controls.backward, get_gui_child(ui, "controlsbackwardbutton"));
	set_key_str(controls.left, get_gui_child(ui, "controlsleftbutton"));
	set_key_str(controls.right, get_gui_child(ui, "controlsrightbutton"));
	set_key_str(controls.interact, get_gui_child(ui, "controlsinteractbutton"));
	set_key_str(controls.shoot, get_gui_child(ui, "controlsshootbutton"));
	set_key_str(controls.crouch, get_gui_child(ui, "controlscrouchbutton"));
	set_key_str(controls.jump, get_gui_child(ui, "controlsjumpbutton"));
}
