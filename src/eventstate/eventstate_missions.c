/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_missions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:17:04 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:06:03 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "eventstate.h"

static void	quit_missions(t_game *game)
{
	game->cureventstate->eventstate = mainmenu;
	mission_return(game, get_gui_child(game->ui, "missionReturnButton"));
}

void		missions_eventstate(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit_missions(game);
}
