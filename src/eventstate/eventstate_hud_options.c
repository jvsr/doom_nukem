/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud_options.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 11:46:43 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:06:13 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "serializer.h"
#include "eventstate.h"

static void	quit_hud_options(t_game *game)
{
	game->cureventstate->eventstate = hud;
	write_settings(game->setting, game->exec_path);
	set_elem_show_clickable(get_gui_child(game->ui, "hudOptionsOverlay"),
																		FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudOptionsMenu"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hud"), TRUE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

void		hud_options_eventstate(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit_hud_options(game);
}
