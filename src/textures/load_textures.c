/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:30:23 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/14 16:52:07 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <errno.h>
#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_num.h"
#include "game.h"
#include "types.h"
#include "error.h"
#include "tga.h"

static void		load_tex(char *loc, const char *exec_path, SDL_Surface **dst)
{
	char		*str;
	SDL_Surface	*surface;

	str = ft_strjoin("game/", loc);
	surface = open_tga_sdl(str, exec_path);
	if (surface == NULL)
		error_msg_sdl(ENOENT, ft_strformat("Missing Texture: %s", loc));
	ft_strdel(&str);
	*dst = surface;
}

static void		load_enemy(char *loc, const char *exec_path, SDL_Surface **dst)
{
	size_t	i;
	size_t	text_id;
	char	*text_loc;

	i = 0;
	while (i < ENEMY_TOTAL_TEXTURE_COUNT)
	{
		text_id = i % ENEMY_MOVE_TEXTURE_COUNT;
		if (i < ENEMY_MOVE_TEXTURE_COUNT * 1)
			text_loc = ft_strformat("%s/Forward_%i", loc, i);
		else if (i < ENEMY_MOVE_TEXTURE_COUNT * 2)
			text_loc = ft_strformat("%s/Back_%i", loc, text_id);
		else if (i < ENEMY_MOVE_TEXTURE_COUNT * 3)
			text_loc = ft_strformat("%s/Left_%i", loc, text_id);
		else if (i < ENEMY_MOVE_TEXTURE_COUNT * 4)
			text_loc = ft_strformat("%s/Right_%i", loc, text_id);
		else if (i < (ENEMY_MOVE_TEXTURE_COUNT * 4) + ENEMY_DEATH_TEXTURE_COUNT)
			text_loc = ft_strformat("%s/Dead_%i", loc, text_id);
		else
			text_loc = ft_strformat("%s/Attack", loc);
		load_tex(text_loc, exec_path, &dst[i]);
		ft_strdel(&text_loc);
		i++;
	}
}

static size_t	load_plain_textures(t_game *game, size_t tex_count)
{
	size_t	i;
	char	**texture_files;

	i = 0;
	texture_files = (char *[]){
		"brick_wall", "skybox_day", "skybox_dusk", "objs/chair_back",
		"objs/chair_front", "objs/chair_left", "objs/chair_right",
		"bloodsplatter", "quartz", "objs/health_pickup", "objs/key", "glass",
		"spike-ball", "rocks", "door", "start_flag", "end_flag", "ammo",
		"slope", "c+", "c-", "f+", "f-", NULL
	};
	while (texture_files[i] != NULL && tex_count + i < TEXTURE_ENEMY0_F0)
	{
		load_tex(texture_files[i], game->exec_path,
			&game->textures[tex_count + i]);
		i++;
	}
	return (i);
}

static size_t	load_enemys(t_game *game, size_t tex_count)
{
	size_t	i;
	char	**enemy_texture_files;

	i = 0;
	enemy_texture_files = (char *[]){
		"enemy0", NULL
	};
	while (enemy_texture_files[i] != NULL && ft_inrange(tex_count +
		(i * ENEMY_TOTAL_TEXTURE_COUNT), TEXTURE_ENEMY0_F0, TEXTURE_COUNT))
	{
		load_enemy(enemy_texture_files[i], game->exec_path,
			&game->textures[tex_count + (i * ENEMY_TOTAL_TEXTURE_COUNT)]);
		i++;
	}
	return (i);
}

void			load_textures(t_game *game)
{
	size_t	tex_count;

	tex_count = 0;
	game->textures = ft_memalloc(sizeof(SDL_Surface *) * TEXTURE_COUNT);
	if (game->textures == NULL)
		error_msg_sdl(ENOMEM, "Unable to allocate textures.");
	tex_count += load_plain_textures(game, tex_count);
	tex_count += load_enemys(game, tex_count) * ENEMY_TOTAL_TEXTURE_COUNT;
	if (tex_count != TEXTURE_COUNT)
		error_msg("Enum sync error", EIO,
			ft_strformat("Texture locations and TEXTURE_COUNT out of sync (%d)",
			tex_count - TEXTURE_COUNT));
}
