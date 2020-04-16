/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:27:39 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/16 12:48:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "setting.h"
#include "onclick.h"
#include "eventstate.h"
#include "serializer.h"

void	remove_options(t_game *game)
{
	t_transform	*menu;
	t_transform	*overlay;

	menu = get_gui_child(game->ui, "optionsMenu");
	overlay = get_gui_child(game->ui, "optionsOverlay");
	set_elem_show_clickable(menu, FALSE);
	set_elem_show_clickable(overlay, FALSE);
	game->cureventstate->eventstate = mainmenu;
}

void	options_return(t_game *game, t_transform *gui)
{
	(void)gui;
	if (game->setting->changed == TRUE || game->setting->confirm == TRUE)
	{
		write_settings(game->setting, game->exec_path);
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

void	hudoptions_return(t_game *game, t_transform *gui)
{
	(void)gui;
	write_settings(game->setting, game->exec_path);
	game->setting->changed = FALSE;
	game->setting->confirm = FALSE;
	set_elem_show_clickable(get_gui_child(game->ui, "hudOptionsMenu"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudOptionsOverlay"),
																		FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hud"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainMenu"), TRUE);
	stop_music();
	fade_in_music(game->audio_man, TITLE_SONG, TITLE_SONG_FADE_IN);
	game->cureventstate->eventstate = mainmenu;
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
	set_key_str(control.forward, get_gui_child(ui, "controlsForwardButton"));
	set_key_str(control.backward, get_gui_child(ui, "controlsBackwardButton"));
	set_key_str(control.left, get_gui_child(ui, "controlsLeftButton"));
	set_key_str(control.right, get_gui_child(ui, "controlsRightButton"));
	set_key_str(control.interact, get_gui_child(ui, "controlsInteractButton"));
	set_key_str(control.shoot, get_gui_child(ui, "controlsShootButton"));
	set_key_str(control.crouch, get_gui_child(ui, "controlsCrouchButton"));
	set_key_str(control.jump, get_gui_child(ui, "controlsJumpButton"));
	game->cureventstate->eventstate = controls;
}
