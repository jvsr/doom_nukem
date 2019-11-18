/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_controls.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:37:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 17:05:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "eventstate.h"

static void	quit_controls(t_game *game)
{
	game->cureventstate->eventstate = options;
	controls_return(game, get_gui_child(game->ui, "controlsreturnbutton"));
}

void		controls_eventstate(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit_controls(game);
}