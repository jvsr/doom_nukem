/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/11 16:11:15 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
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
#include "sdl_thread.h"
#include "textures.h"

static void		player_init(t_game *game)
{
	game->player = ft_memalloc(sizeof(t_player));
	if (game->player == NULL)
		error_msg_errno("Could not allocate Game Player");
	game->player->fov = &game->setting->fov;
	get_vector_from_angle(game->player->angle, &game->player->forward);
	game->player->player_height = PLAYER_HEIGHT;
	game->player->height = PLAYER_HEIGHT;
	game->player->health = PLAYER_MAX_HEALTH;
	ft_memcpy(&game->player->mag, &(t_coord){wrap_float(game->player->angle -
		(game->setting->fov / 2), 0.0, 360.0), wrap_float(game->player->angle +
		(game->setting->fov / 2), 0.0, 360.0)}, sizeof(t_coord));
}

static void		map_init(t_game *game)
{
	game->map = ft_memalloc(sizeof(t_map));
	if (!game->map)
		error_msg_errno("Could not allocate Game Map");
	game->map->sectors = ft_memalloc(sizeof(t_sector) * 5);
	if (!game->map)
		error_msg_errno("Could not allocate Map Sector");
	game->map->sector_count = 4;
	game->map->has_skybox = TRUE;
	game->map->skybox = TEXTURE_SKYBOX_DAY;

	//Sector 1
	game->map->sectors[0].ceil = 150;
	game->map->sectors[0].floor = 0;
	game->map->sectors[0].wall_count = 5;
	game->map->sectors[0].walls = ft_memalloc(sizeof(t_wall) * 5);
	game->map->sectors[0].light_value = 0.5;
	if (game->map->sectors[0].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[0].walls[0] = (t_wall){(t_coord){-20, -20}, (t_coord){20, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[1] = (t_wall){(t_coord){20, -20}, (t_coord){40, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[1].is_portal = TRUE;
	game->map->sectors[0].walls[1].window = &game->map->sectors[3];
	game->map->sectors[0].walls[2] = (t_wall){(t_coord){40, -20}, (t_coord){40, 20}, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[3] = (t_wall){(t_coord){40, 20}, (t_coord){-20, 20}, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[4] = (t_wall){(t_coord){-20, 20}, (t_coord){-20, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 2}, NULL};
	game->map->sectors[0].walls[4].is_portal = TRUE;
	game->map->sectors[0].walls[4].window = &game->map->sectors[1];
	game->map->sectors[0].has_ceiling = TRUE;
	game->map->sectors[0].object_count = 3;
	game->map->sectors[0].object = ft_memalloc(sizeof(t_object) * 4);
	if (game->map->sectors[0].object == NULL)
		error_msg_errno("Could not allocate Map Objects");
	game->map->sectors[0].object[0].pos = (t_coord){0, 0};
	game->map->sectors[0].object[0].size = (t_coord){10, 10};
	game->map->sectors[0].object[0].img = chair_init(&game->map->sectors[0].object[0], 10);
	game->map->sectors[0].object[1].pos = (t_coord){3, 3};
	game->map->sectors[0].object[1].size = (t_coord){4, 15};
	game->map->sectors[0].object[1].img = enemy_init(&game->map->sectors[0].object[1], TEXTURE_ENEMY0_F0);
	game->map->sectors[0].object[2].pos = (t_coord){-2, -2};
	game->map->sectors[0].object[2].size = (t_coord){4, 4};
	game->map->sectors[0].object[2].img = single_init(TEXTURE_HEALTH_PICKUP, &game->map->sectors[0].object[2]);
	game->map->sectors[0].object[2].col_type = COLLISION_PICKUP;
	t_decal *decal = ft_memalloc(sizeof(t_decal));
	decal->texture = single_init(TEXTURE_BLOOD_SPLATTER, NULL);
	decal->pos = (t_coord){0.8, 0.0};
	decal->size = (t_coord){4, 10};
	game->map->sectors[0].walls[2].decals = ft_lstnew(decal, sizeof(decal));
	decal = ft_memalloc(sizeof(t_decal));
	decal->texture = single_init(TEXTURE_BLOOD_SPLATTER, NULL);
	decal->pos = (t_coord){0.0, 0.0};
	decal->size = (t_coord){4, 10};
	game->map->sectors[0].walls[3].decals = ft_lstnew(decal, sizeof(decal));

	//Sector 2
	game->map->sectors[1].ceil = 100;
	game->map->sectors[1].floor = -10;
	game->map->sectors[1].wall_count = 4;
	game->map->sectors[1].walls = ft_memalloc(sizeof(t_wall) * 4);
	game->map->sectors[1].light_value = 1.0;
	if (game->map->sectors[1].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[1].walls[0] = (t_wall){(t_coord){-30, -20}, (t_coord){-20, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){2, 0.5}, NULL};
	game->map->sectors[1].walls[1] = (t_wall){(t_coord){-30, 20}, (t_coord){-30, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[1].walls[1].is_portal = TRUE;
	game->map->sectors[1].walls[1].window = &game->map->sectors[2];
	game->map->sectors[1].walls[2] = (t_wall){(t_coord){-20, 20}, (t_coord){-30, 20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){2, 0.5}, NULL};
	game->map->sectors[1].walls[3] = (t_wall){(t_coord){-20, -20}, (t_coord){-20, 20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[1].walls[3].is_portal = TRUE;
	game->map->sectors[1].walls[3].window = &game->map->sectors[0];
	game->map->sectors[1].has_ceiling = TRUE;
	game->map->sectors[1].object_count = 0;
	game->map->sectors[1].object = NULL;

	//Sector 3
	game->map->sectors[2].ceil = 40;
	game->map->sectors[2].floor = 10;
	game->map->sectors[2].wall_count = 4;
	game->map->sectors[2].walls = ft_memalloc(sizeof(t_wall) * 4);
	game->map->sectors[2].light_value = 0.5;
	if (game->map->sectors[2].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[2].walls[0] = (t_wall){(t_coord){-40, -20}, (t_coord){-30, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[1] = (t_wall){(t_coord){-40, 20}, (t_coord){-40, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[2] = (t_wall){(t_coord){-30, 20}, (t_coord){-40, 20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[3] = (t_wall){(t_coord){-30, -20}, (t_coord){-30, 20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[3].is_portal = TRUE;
	game->map->sectors[2].walls[3].window = &game->map->sectors[1];
	game->map->sectors[2].object_count = 0;
	game->map->sectors[2].object = NULL;
	game->map->sectors[2].has_ceiling = FALSE;

	//Sector 4
	game->map->sectors[3].ceil = 13;
	game->map->sectors[3].floor = 5;
	game->map->sectors[3].wall_count = 4;
	game->map->sectors[3].walls = ft_memalloc(sizeof(t_wall) * 4);
	game->map->sectors[3].light_value = 0.5;
	if (game->map->sectors[3].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[3].walls[0] = (t_wall){(t_coord){40, -30}, (t_coord){40, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[1] = (t_wall){(t_coord){20, -30}, (t_coord){40, -30}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[2] = (t_wall){(t_coord){20, -20}, (t_coord){20, -30}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[3] = (t_wall){(t_coord){40, -20}, (t_coord){20, -20}, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[3].is_portal = TRUE;
	game->map->sectors[3].walls[3].window = &game->map->sectors[0];
	game->map->sectors[3].has_ceiling = TRUE;
	game->map->sectors[3].object_count = 0;
	game->map->sectors[3].object = NULL;
}

void			init_function(t_game *game)
{
	init_audio(game);
	init_gui(game);
	load_textures(game);
	init_main_menu(game);
	init_keymap(game);
	player_init(game);
	map_init(game);
	game->pool = sdl_new_pool(INIT_THREADPOOL_WORKERS,
					FALSE, INIT_THREADPOOL_CENTRALIZED);
	game->cureventstate->eventstate = splash;
}
