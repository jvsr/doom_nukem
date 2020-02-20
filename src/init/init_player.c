/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:17:24 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/19 21:26:29 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "coord.h"

void	init_player(t_game *game)
{
	game->player->pos.x = 0;
	game->player->pos.y = 0;
	game->player->cur_sector = 0;
	game->player->height = PLAYER_HEIGHT;
	game->player->mag = (t_mag){cosf(0), sinf(0)};
}
