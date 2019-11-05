/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 15:52:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_mem.h"

#include "game.h"
#include "setting.h"
#include "init.h"
#include "error.h"
#include "gametime.h"
#include "audio.h"
#include "tga.h"
#include "serializer.h"

#include <fcntl.h>

static void		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		error_msg_sdl(EIO, "Failed to init SDL");
	if (TTF_Init() < 0)
		error_msg_sdl(ENOMEM, "Failed to init TTF");
}

static t_game	*alloc_game(void)
{
	t_game	*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	if (game == NULL)
		error_msg_sdl(ENOMEM, "Failed to alloc game");
	return (game);
}

static void		init_game(t_game *game)
{
	game->state = running;
	init_gametime(&game->starttime);
	game->cursoractive = TRUE;
}

static void		init_settings(t_game *game)
{
	int			fd;
	t_setting	*setting;

	fd = open("./resources/data/settings/settings.conf", O_RDONLY);
	if (fd == -1)
	{
		setting = (t_setting *)ft_memalloc(sizeof(t_setting));
		if (setting == NULL)
			error_msg_errno("Failed to alloc settings");
		setting->sensitivity = 1.0;
		setting->music_volume = 0.8;
		setting->sound_volume = 0.8;
		setting->fov = 75;
		setting->resolution.x = INIT_WIDTH;
		setting->resolution.y = INIT_HEIGHT;
		setting->resolution_type = fullscreen;
		game->setting = setting;
		return ;
	}
	close(fd);
	game->setting = read_settings();
}

t_game			*init(char **argv, char **envp)
{
	t_game *game;

	init_sdl();
	game = alloc_game();
	game->argv = argv;
	game->envp = envp;
	init_settings(game);
	init_window_surface(game);
	init_game(game);
	init_audio(game);
	init_gui(game);
	init_keymap(game);
	return (game);
}
