/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/25 17:37:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "game.h"
#include "setting.h"
#include "parse_map.h"
#include "init.h"
#include "error.h"
#include "eventstate.h"

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

static void		set_basic_args(t_game *game, char **argv, char **envp)
{
	const size_t	exec_len = ft_strlen(argv[0]);
	size_t			path_len;

	game->argv = argv;
	game->envp = envp;
	game->exec_name = ft_strdup(ft_strrchr(argv[0], '/') + 1);
	if (game->exec_name == NULL)
		error_msg_errno("Failed to alloc exec name");
	path_len = exec_len - ft_strlen(game->exec_name);
	g_doom_dir = ft_strndup(argv[0], path_len);
	if (g_doom_dir == NULL)
		error_msg_errno("Failed to alloc doom dir");
}

t_game			*init(char **argv, char **envp)
{
	t_game *game;

	init_sdl();
	game = alloc_game();
	set_basic_args(game, argv, envp);
	init_settings(game);
	init_window_surface(game);
	init_game(game);
	init_audio(game);
	init_gui(game);
	init_keymap(game);
	init_eventstate(game);
	parse_map("map/campaign/doom1.wad", game);
	return (game);
}
