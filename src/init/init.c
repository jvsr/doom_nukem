/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/10 13:07:54 by euan          ########   odam.nl         */
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
	game->player->health += 10;
	(void)cur_sector;
}

static void		init_player(t_game *game)
{
	game->player = ft_memalloc(sizeof(t_player));
	if (game->player == NULL)
		error_msg_errno("Could not allocate Game Player");
	game->player->fov = &game->setting->fov;
	get_vector_from_angle(game->player->angle, &game->player->forward);
	game->player->player_height = PLAYER_HEIGHT;
	game->player->height = PLAYER_HEIGHT;
	game->player->health = PLAYER_MAX_HEALTH;
	game->player->mag = (t_mag){cosf(0), sinf(0)};
	game->player->ammo = 1000;
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
	game->map->sector_count = 1;
	if (!game->map)
		error_msg_errno("Could not allocate Game Map");
	game->map->sectors = ft_memalloc(sizeof(t_sector) * (game->map->sector_count + 1));
	if (!game->map)
		error_msg_errno("Could not allocate Map Sector");
	game->map->has_skybox = FALSE;
	game->map->skybox = TEXTURE_SKYBOX_DAY;

	//Sector 1
	game->map->sectors[0].ceil = 40;
	game->map->sectors[0].floor = 0;
	game->map->sectors[0].wall_count = 4;
	game->map->sectors[0].walls = ft_memalloc(sizeof(t_wall) * (game->map->sectors[0].wall_count + 1));
	game->map->sectors[0].light_value = 0.5;
	if (game->map->sectors[0].walls == NULL)
		error_msg_errno("Could not allocate Map Walls");
	game->map->sectors[0].walls[0] = (t_wall){(t_coord){10, -10}, (t_coord){10, 10}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.2}, NULL, 0};
	game->map->sectors[0].walls[1] = (t_wall){(t_coord){10, 10}, (t_coord){-10, 10}, FALSE, FALSE, NULL, single_init(TEXTURE_BRICK_WALL, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.2}, NULL, 0};
	game->map->sectors[0].walls[2] = (t_wall){(t_coord){-10, 10}, (t_coord){-10, -10}, FALSE, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL),single_init(TEXTURE_GLASS, NULL), (t_coord){0.2, 0.2}, NULL, 0};
	game->map->sectors[0].walls[3] = (t_wall){(t_coord){-10, -10}, (t_coord){10, -10}, FALSE, FALSE, NULL, single_init(TEXTURE_QUARTZ, NULL), single_init(TEXTURE_GLASS, NULL),(t_coord){0.2, 0.2}, NULL, 0};
	game->map->sectors[0].has_ceiling = TRUE;
	game->map->sectors[0].floor_tex = TEXTURE_QUARTZ;
	game->map->sectors[0].ceil_tex = TEXTURE_QUARTZ;
	game->map->sectors[0].has_slope = FALSE;
	game->map->sectors[0].swall = NULL;
	game->map->sectors[0].angle = 0;
}

void			*init_function(t_game *game)
{
	init_threadpool(game);
	init_audio(game);
	init_gui(game);
	load_textures(game);
	init_main_menu(game);
	init_keymap(game);
	init_player(game);
	map_init(game);
	game->cureventstate->eventstate = splash;
	return (NULL);
}
