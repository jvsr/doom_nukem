/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud_win.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 16:29:42 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/09 16:33:30 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "serializer.h"
#include "eventstate.h"

static void	quit_hud_win(t_game *game)
{
	set_elem_show_clickable(get_gui_child(game->ui, "hud"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudWin"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainMenu"), TRUE);
	game->cureventstate->eventstate = mainmenu;
}

void		hud_win_eventstate(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit_hud_win(game);
}
