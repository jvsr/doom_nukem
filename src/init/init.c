/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/13 18:03:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "game.h"
#include "audio.h"
#include "init.h"
#include "player.h"
#include "cmath.h"
#include "setting.h"
#include "eventstate.h"
#include "parse_map.h"
#include "renderer.h"
#include "error.h"

static void		player_init(t_game *game)
{
	game->player = ft_memalloc(sizeof(t_player));
	if (game->player == NULL)
		error_msg_errno("Could not allocate Game Player");
	get_vector_from_angle(game->player->angle, &game->player->forward);
	game->player->height = PLAYER_HEIGHT;
	ft_memcpy(&game->player->mag, &(t_coord){wrap_float(game->player->angle -
		(game->setting->fov / 2), 0.0, 360.0), wrap_float(game->player->angle +
		(game->setting->fov / 2), 0.0, 360.0)}, sizeof(t_coord));
}

void			init_function(t_game *game)
{
	init_audio(game);
	init_gui(game);
	load_textures(game);
	init_main_menu(game);
	init_keymap(game);
	player_init(game);
	parse_map("map/campaign/doom1.wad", game);
	game->cureventstate->eventstate = splash;
}
