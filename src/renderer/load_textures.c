/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:30:23 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/14 15:46:10 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <errno.h>
#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "game.h"
#include "types.h"
#include "error.h"
#include "tga.h"

static SDL_Surface	*load_texture(char *loc, const char *exec_path)
{
	char		*str;
	SDL_Surface	*surface;

	str = ft_strjoin("game/", loc);
	surface = open_tga_sdl(str, exec_path);
	if (surface == NULL)
		error_msg_sdl(ENOENT, "Missing Texture");
	ft_strdel(&str);
	return (surface);
}

static	void		load_enemy(char *loc,
					const char *exec_path, size_t *i, SDL_Surface **textures)
{
	size_t start;
	size_t val;

	start = *i;
	while (*i - start < 19)
	{
		val = *i - start;
		if (val < 4)
			textures[*i] = load_texture(
				ft_strformat("%s/Forward_%i", loc, val), exec_path);
		else if (val < 8)
			textures[*i] = load_texture(
				ft_strformat("%s/Back_%i", loc, val - 4), exec_path);
		else if (val < 12)
			textures[*i] = load_texture(
				ft_strformat("%s/Left_%i", loc, val - 8), exec_path);
		else if (val < 16)
			textures[*i] = load_texture(
				ft_strformat("%s/Right_%i", loc, val - 12), exec_path);
		else if (val < 18)
			textures[*i] = load_texture(
				ft_strformat("%s/Dead_%i", loc, val - 16), exec_path);
		else
			textures[*i] = load_texture(
				ft_strformat("%s/Attack", loc), exec_path);
		(*i)++;
	}
}

void				load_textures(t_game *game)
{
	char	**files;
	size_t	index;

	files = (char *[]){
		"brick_wall", "skybox_day", "skybox_dusk", "objs/lamp",
		"objs/chair_back", "objs/chair_front", "objs/chair_left",
		"objs/chair_right", "bloodsplatter", "quartz", "objs/health_pickup",
		"objs/key"
	};
	index = 0;
	game->textures = ft_memalloc(sizeof(SDL_Surface *) * TEXTURE_COUNT);
	if (game->textures == NULL)
		error_msg_sdl(ENOMEM, "Unable to allocate textures.");
	while (index < TEXTURE_ENEMY0_F0)
	{
		game->textures[index] = load_texture(files[index], game->exec_path);
		index++;
	}
	load_enemy("enemy0", game->exec_path, &index, game->textures);
}
