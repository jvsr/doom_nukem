/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud_died.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidge <ehollidge@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 11:46:43 by ehollidge     #+#    #+#                 */
/*   Updated: 2020/04/06 12:06:15 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "keymap.h"
#include "onclick.h"
#include "serializer.h"
#include "eventstate.h"

static void	quit_hud_died(t_game *game)
{
	game->cureventstate->eventstate = mainmenu;
	set_elem_show_clickable(get_gui_child(game->ui, "hudDied"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainMenu"), TRUE);
	fade_in_music(game->audio_man, TITLE_SONG, TITLE_SONG_FADE_IN);
}

void		eventstate_hud_died(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit_hud_died(game);
}
