/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/14 21:04:11 by euan          ########   odam.nl         */
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

void			test_function(t_game *game, t_sector *cur_sector)
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
	game->player->ammo = 15;
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

void			*init_function(t_game *game)
{
	init_threadpool(game);
	init_audio(game);
	init_gui(game);
	load_textures(game);
	init_main_menu(game);
	init_keymap(game);
	init_player(game);
	game->cureventstate->eventstate = splash;
	return (NULL);
}
