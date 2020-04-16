/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud_died.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidge <ehollidge@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 11:46:43 by ehollidge     #+#    #+#                 */
/*   Updated: 2020/04/15 16:07:26 by jvisser       ########   odam.nl         */
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

void		eventstate_hud_died(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		hud_diedmainmenu(game, NULL);
}
