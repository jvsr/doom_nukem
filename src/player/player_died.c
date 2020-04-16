/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_died.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 12:04:45 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:22 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "eventstate.h"
#include "game.h"
#include "gui.h"

void		player_died(t_game *game)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudDied"), TRUE);
	game->cureventstate->eventstate = hud_died;
}
