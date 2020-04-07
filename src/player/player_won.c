/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_won.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 12:39:03 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:15 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "eventstate.h"
#include "game.h"
#include "gui.h"

void		player_won(t_game *game)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudWin"), TRUE);
	game->cureventstate->eventstate = hud_win;
}
