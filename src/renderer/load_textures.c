/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:30:23 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/24 17:23:57 by ehollidg      ########   odam.nl         */
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

static SDL_Surface	*get_texture(char *loc, const char *exec_path)
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

void				load_textures(t_game *game)
{
	char	**files;
	size_t	index;

	files = (char *[]){
		"brick_wall"
	};
	index = 0;
	game->textures = ft_memalloc(sizeof(SDL_Surface *) * TEXTURE_COUNT);
	if (game->textures == NULL)
		error_msg_sdl(ENOMEM, "Unable to allocate textures.");
	while (index < TEXTURE_COUNT)
	{
		game->textures[index] = get_texture(files[index], game->exec_path);
		index++;
	}
}
