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
#include "rinfo.h"

static void		player_init(t_game *game)
{
	game->player = ft_memalloc(sizeof(t_player));
	if (game->player == NULL)
		error_msg_errno("Could not allocate Game Player");
	game->player->fov = &game->setting->fov;
	get_vector_from_angle(game->player->angle, &game->player->forward);
	game->player->height = PLAYER_HEIGHT;
	ft_memcpy(&game->player->mag, &(t_coord){wrap_float(game->player->angle -
		(game->setting->fov / 2), 0.0, 360.0), wrap_float(game->player->angle +
		(game->setting->fov / 2), 0.0, 360.0)}, sizeof(t_coord));
}

static void		map_init(t_game *game)
{
	game->map = ft_memalloc(sizeof(t_map));
	if (!game->map)
		error_msg_errno("Could not allocate Game Map");
	game->map->sectors = ft_memalloc(sizeof(t_sector) * 2);
	if (!game->map)
		error_msg_errno("Could not allocate Map Sector");
	game->map->sector_count = 2;

	//Sector 1
	game->map->sectors[0].ceil = 40;
	game->map->sectors[0].floor = 0;
	game->map->sectors[0].wall_count = 4;
	game->map->sectors[0].walls = ft_memalloc(sizeof(t_wall) * 4);
	if (game->map->sectors[0].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[0].walls[0] = (t_wall){(t_coord){-20, -20}, (t_coord){20, -20}, FALSE, NULL};
	game->map->sectors[0].walls[1] = (t_wall){(t_coord){20, -20}, (t_coord){20, 20}, FALSE, NULL};
	game->map->sectors[0].walls[2] = (t_wall){(t_coord){20, 20}, (t_coord){-20, 20}, FALSE, NULL};
	game->map->sectors[0].walls[3] = (t_wall){(t_coord){-20, 20}, (t_coord){-20, -20}, FALSE, NULL};
	game->map->sectors[0].walls[3].is_portal = TRUE;
	game->map->sectors[0].walls[3].window = &game->map->sectors[1];

	//Sector 2
	game->map->sectors[1].ceil = 30;
	game->map->sectors[1].floor = 10;
	game->map->sectors[1].wall_count = 4;
	game->map->sectors[1].walls = ft_memalloc(sizeof(t_wall) * 4);
	if (game->map->sectors[1].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[1].walls[0] = (t_wall){(t_coord){-20, -20}, (t_coord){-30, -20}, FALSE, NULL};
	game->map->sectors[1].walls[1] = (t_wall){(t_coord){-30, -20}, (t_coord){-30, 20}, FALSE, NULL};
	game->map->sectors[1].walls[2] = (t_wall){(t_coord){-30, 20}, (t_coord){-20, 20}, FALSE, NULL};
	game->map->sectors[1].walls[3] = (t_wall){(t_coord){-20, 20}, (t_coord){-20, -20}, FALSE, NULL};
	game->map->sectors[1].walls[3].is_portal = TRUE;
	game->map->sectors[1].walls[3].window = &game->map->sectors[0];
}

void			init_function(t_game *game)
{
	init_audio(game);
	init_gui(game);
	load_textures(game);
	init_main_menu(game);
	init_keymap(game);
	map_init(game);
	player_init(game);
	parse_map("map/campaign/doom1.wad", game);
	game->cureventstate->eventstate = splash;
}
