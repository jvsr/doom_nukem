/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_options_confirmation.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:19:02 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 17:20:07 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "eventstate.h"

static void	quit_options_confirmation(t_game *game)
{
	game->cureventstate->eventstate = options;
	confirmation_return(game,
		get_gui_child(game->ui, "confirmationreturnbutton"));
}

void		options_confirmation_eventstate(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit_options_confirmation(game);
}
