/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/02 10:55:22 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "libft/ft_printf.h"
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

void	test_function(t_game *game, t_sector *cur_sector)
{
	game->player->heightoffset += 100;
	cur_sector->ceil += 120;
}

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

static void		init_threadpool(t_game *game)
{
	ssize_t	core_count;

	core_count = sdl_get_core_count();
	if (core_count == -1)
	{
		core_count = INIT_THREADPOOL_SIZE_FALLBACK;
		ft_dprintf(2, "Error getting core count. Using fallback size '%zi'\n",
					core_count);
	}
	game->pool = sdl_new_tpool(core_count, TFLAG_POOL_ALLOC_ON_EXEC);
}

void			map_init(t_game *game)
{
	game->map = ft_memalloc(sizeof(t_map));
	game->map->sector_count = 4;
	if (!game->map)
		error_msg_errno("Could not allocate Game Map");
	game->map->sectors = ft_memalloc(sizeof(t_sector) * (game->map->sector_count + 1));
	if (!game->map)
		error_msg_errno("Could not allocate Map Sector");
	game->map->has_skybox = TRUE;
	game->map->skybox = TEXTURE_SKYBOX_DAY;

	//Sector 1
	game->map->sectors[0].ceil = 150;
	game->map->sectors[0].floor = 0;
	game->map->sectors[0].wall_count = 6;
	game->map->sectors[0].walls = ft_memalloc(sizeof(t_wall) * (game->map->sectors[0].wall_count + 1));
	game->map->sectors[0].light_value = 0.5;
	if (game->map->sectors[0].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[0].walls[0] = (t_wall){(t_coord){-20, -20}, (t_coord){20, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[1] = (t_wall){(t_coord){20, -20}, (t_coord){40, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[1].is_portal = TRUE;
	game->map->sectors[0].walls[1].is_window = TRUE;
	game->map->sectors[0].walls[1].window = &game->map->sectors[3];
	game->map->sectors[0].walls[2] = (t_wall){(t_coord){40, -20}, (t_coord){40, 20}, FALSE, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[3] = (t_wall){(t_coord){40, 20}, (t_coord){-20, 20}, FALSE, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].walls[4] = (t_wall){(t_coord){-20, 20}, (t_coord){-20, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 2}, NULL};
	game->map->sectors[0].walls[4].is_portal = TRUE;
	game->map->sectors[0].walls[4].window = &game->map->sectors[1];
	game->map->sectors[0].walls[5] = (t_wall){(t_coord){30, 10}, (t_coord){10, 10}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[0].has_ceiling = TRUE;
	game->map->sectors[0].object_count = 5;
	game->map->sectors[0].floor_tex = TEXTURE_BRICK_WALL;

	t_object *o = (t_object*)ft_memalloc(sizeof(t_object));
	game->map->sectors[0].objects = ft_lstnew(o, sizeof(t_object*));
	o = (t_object*)ft_memalloc(sizeof(t_object));
	game->map->sectors[0].objects->next = ft_lstnew(o, sizeof(t_object*));;
	o = (t_object*)ft_memalloc(sizeof(t_object));
	game->map->sectors[0].objects->next->next = ft_lstnew(o, sizeof(t_object*));
	o = (t_object*)ft_memalloc(sizeof(t_object));
	game->map->sectors[0].objects->next->next->next = ft_lstnew(o, sizeof(t_object*));
	o = (t_object*)ft_memalloc(sizeof(t_object));
	game->map->sectors[0].objects->next->next->next->next = ft_lstnew(o, sizeof(t_object*));

	t_object *obj = game->map->sectors[0].objects->content;
	obj->pos = (t_coord){5, 0};
	obj->size = (t_coord){10, 10};
	obj->img = chair_init(obj, 10);
	obj->is_enemy = FALSE;
	obj->can_col = TRUE;
	obj->col_radius = 1.0;

	obj = game->map->sectors[0].objects->next->content;
	obj->pos = (t_coord){3, 3};
	obj->size = (t_coord){4, 15};
	obj->img = enemy_init(obj, TEXTURE_ENEMY0_F0);
	obj->is_enemy = TRUE;
	obj->can_col = TRUE;
	obj->col_radius = 1.0;

	obj = game->map->sectors[0].objects->next->next->content;
	obj->pos = (t_coord){-5, -2};
	obj->size = (t_coord){4, 4};
	obj->img = single_init(TEXTURE_HEALTH_PICKUP, obj);
	obj->can_col = FALSE;
	obj->is_enemy = FALSE;
	obj->col_radius = 1.0;
	obj->on_collide = health_pickup;

	obj = game->map->sectors[0].objects->next->next->next->content;
	obj->pos = (t_coord){0, 5};
	obj->size = (t_coord){4, 4};
	obj->img = single_init(TEXTURE_KEYS, obj);
	obj->can_col = FALSE;
	obj->is_enemy = FALSE;
	obj->col_radius = 1.0;
	obj->on_collide = key_pickup;

	obj = game->map->sectors[0].objects->next->next->next->next->content;
	obj->pos = (t_coord){5, 5};
	obj->size = (t_coord){8, 8};
	obj->img = single_init(TEXTURE_SPIKES, obj);
	obj->can_col = TRUE;
	obj->is_enemy = FALSE;
	obj->col_radius = 1.3;
	obj->on_collide = spike_damage;
	obj->data = ft_memalloc(sizeof(t_uint64));

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
	game->map->sectors[1].walls = ft_memalloc(sizeof(t_wall) * (game->map->sectors[1].wall_count + 1));
	game->map->sectors[1].light_value = 1.0;
	if (game->map->sectors[1].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[1].walls[0] = (t_wall){(t_coord){-30, -20}, (t_coord){-20, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){2, 0.5}, NULL};
	game->map->sectors[1].walls[1] = (t_wall){(t_coord){-30, 20}, (t_coord){-30, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[1].walls[1].is_portal = TRUE;
	game->map->sectors[1].walls[1].window = &game->map->sectors[2];
	game->map->sectors[1].walls[2] = (t_wall){(t_coord){-20, 20}, (t_coord){-30, 20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){2, 0.5}, NULL};
	game->map->sectors[1].walls[3] = (t_wall){(t_coord){-20, -20}, (t_coord){-20, 20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[1].walls[3].is_portal = TRUE;
	game->map->sectors[1].walls[3].window = &game->map->sectors[0];
	game->map->sectors[1].floor_tex = TEXTURE_BRICK_WALL;
	game->map->sectors[1].has_ceiling = TRUE;
	game->map->sectors[1].object_count = 0;
	game->map->sectors[1].objects = NULL;

	//Sector 3
	game->map->sectors[2].ceil = 40;
	game->map->sectors[2].floor = 10;
	game->map->sectors[2].wall_count = 5;
	game->map->sectors[2].walls = ft_memalloc(sizeof(t_wall) * (game->map->sectors[2].wall_count + 1));
	game->map->sectors[2].light_value = 0.5;
	if (game->map->sectors[2].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[2].walls[0] = (t_wall){(t_coord){-40, -20}, (t_coord){-30, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[1] = (t_wall){(t_coord){-30, -20}, (t_coord){-30, 20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[2] = (t_wall){(t_coord){-30, 20}, (t_coord){-30, 40}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[3] = (t_wall){(t_coord){-30, 40}, (t_coord){-40, 40}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[4] = (t_wall){(t_coord){-40, 40}, (t_coord){-40, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[2].walls[1].is_portal = TRUE;
	game->map->sectors[2].walls[1].window = &game->map->sectors[1];
	game->map->sectors[2].object_count = 0;
	game->map->sectors[2].objects = NULL;
	game->map->sectors[2].has_ceiling = FALSE;
	game->map->sectors[2].floor_tex = TEXTURE_BRICK_WALL;

	//Sector 4
	game->map->sectors[3].ceil = 13;
	game->map->sectors[3].floor = 5;
	game->map->sectors[3].wall_count = 4;
	game->map->sectors[3].f_enter = test_function;
	game->map->sectors[3].walls = ft_memalloc(sizeof(t_wall) * (game->map->sectors[3].wall_count + 1));
	game->map->sectors[3].light_value = 0.5;
	if (game->map->sectors[3].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[3].walls[0] = (t_wall){(t_coord){40, -30}, (t_coord){40, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[1] = (t_wall){(t_coord){20, -30}, (t_coord){40, -30}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[2] = (t_wall){(t_coord){20, -20}, (t_coord){20, -30}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[3] = (t_wall){(t_coord){40, -20}, (t_coord){20, -20}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	game->map->sectors[3].walls[3].is_portal = TRUE;
	game->map->sectors[3].walls[3].is_window = TRUE;
	game->map->sectors[3].walls[3].window = &game->map->sectors[0];
	game->map->sectors[3].has_ceiling = TRUE;
	game->map->sectors[3].object_count = 0;
	game->map->sectors[3].objects = NULL;
	game->map->sectors[3].floor_tex = TEXTURE_BRICK_WALL;

	// //Sector 5
	// game->map->sectors[4].ceil = 150;
	// game->map->sectors[4].floor = 0;
	// game->map->sectors[4].wall_count = 4;
	// game->map->sectors[4].walls = ft_memalloc(sizeof(t_wall) * (game->map->sectors[4].wall_count + 1));
	// game->map->sectors[4].light_value = 0.5;
	// if (game->map->sectors[4].walls == NULL)
	// 	error_msg_errno("Could not allocate Map Walls");
	// game->map->sectors[4].walls[0] = (t_wall){(t_coord){-5, -5}, (t_coord){5, -5}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.5}, NULL};
	// game->map->sectors[4].walls[1] = (t_wall){(t_coord){5, -5}, (t_coord){5, -5}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	// game->map->sectors[4].walls[2] = (t_wall){(t_coord){5, -5}, (t_coord){5, 5}, FALSE, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.5}, NULL};
	// game->map->sectors[4].walls[3] = (t_wall){(t_coord){5, 5}, (t_coord){-5, 5}, FALSE, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.5}, NULL};
	// game->map->sectors[4].has_ceiling = TRUE;
	// game->map->sectors[4].object_count = 4;
}

void			*init_function(t_game *game)
{
	init_threadpool(game);
	init_audio(game);
	init_gui(game);
	load_textures(game);
	init_main_menu(game);
	init_keymap(game);
	player_init(game);
	map_init(game);
	init_ftable(game);
	game->cureventstate->eventstate = splash;
	return (NULL);
}
