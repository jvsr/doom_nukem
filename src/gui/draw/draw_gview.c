/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_gview.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:29:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/04 13:29:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_extra.h"
#include "renderer.h"
#include "game.h"
#include "gui.h"
#include "rinfo.h"
#include "player.h"
#include "coord.h"

/*
** * Gui internal function
*/

void		draw_gview(SDL_Surface *dst, t_game *game)
{
	render(game, dst);
}
