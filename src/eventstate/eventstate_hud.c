/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:13:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 17:25:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "eventstate.h"

static void set_mouse_capture()
{
	static int caught = 0;

	SDL_SetRelativeMouseMode(caught);
	caught = !caught;
}

void		hud_eventstate(t_game *game, SDL_Event event)
{
	(void)game;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		set_mouse_capture();
}
