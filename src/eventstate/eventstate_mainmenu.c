/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_mainmenu.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:16:15 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 17:18:24 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "game.h"
#include "keymap.h"
#include "eventstate.h"

void	mainmenu_eventstate(t_game *game, SDL_Event event)
{
	(void)game;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit(0);
}
