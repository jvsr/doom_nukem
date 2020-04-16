/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_died.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 12:33:27 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/16 12:44:02 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "eventstate.h"
#include "renderer.h"
#include "audio.h"
#include "game.h"
#include "init.h"
#include "gui.h"

void		hud_diedmainmenu(t_game *game, t_transform *gui)
{
	(void)gui;
	game->cureventstate->eventstate = mainmenu;
	set_elem_show_clickable(get_gui_child(game->ui, "hud"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudDied"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudWin"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainMenu"), TRUE);
	stop_music();
	fade_in_music(game->audio_man, TITLE_SONG, TITLE_SONG_FADE_IN);
}
