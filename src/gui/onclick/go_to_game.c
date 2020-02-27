/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_to_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 13:58:52 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/13 16:20:31 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_stdinc.h>

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "gui_config.h"
#include "eventstate.h"

void	go_to_game(t_game *game, t_transform *gui)
{
	(void)gui;
	SDL_SetRelativeMouseMode(SDL_TRUE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainmenu"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hud"), TRUE);
	game->cureventstate->eventstate = hud;
	fade_out_music(TITLE_SONG_FADE_OUT);
}
