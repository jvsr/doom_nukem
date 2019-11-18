/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_map_editor_select.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 11:06:09 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/14 12:23:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "eventstate.h"

static void	quit_map_editor_select(t_game *game)
{
	game->cureventstate->eventstate = mainmenu;
	map_editor_select_return(
		game, get_gui_child(game->ui, "mapeditorselectboxreturnbutton"));
}

void	map_editor_select_eventstate(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit_map_editor_select(game);
}
