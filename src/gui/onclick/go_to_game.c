/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_to_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:58:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 13:58:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "gui_config.h"
#include "eventstate.h"

void	go_to_game(t_game *game, t_transform *gui)
{
	(void)gui;
	set_elem_show_clickable(get_gui_child(game->ui, "mainmenu"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hud"), TRUE);
	game->cureventstate->eventstate = hud;
	stop_music();
}
