/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:17:24 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:46:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "coord.h"

void	init_player(t_game *game)
{
	game->player->pos.x = 30;
	game->player->pos.y = -25;
	game->player->cur_sector = 3;
	game->player->height = PLAYER_HEIGHT;
	game->player->mag = (t_mag){cosf(0), sinf(0)};
	game->player->health = PLAYER_MAX_HEALTH;
	game->player->is_dead = FALSE;
	game->player->keys = 0;
}
