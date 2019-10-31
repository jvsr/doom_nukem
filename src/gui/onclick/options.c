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
	t_transform	*controls;

	(void)gui;
	controls = get_gui_child(game->ui, "controls");
	set_elem_show_clickable(controls, TRUE);
}
