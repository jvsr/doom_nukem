/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_prerequisites.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 11:32:47 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/16 14:31:28 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "game.h"
#include "setting.h"
#include "init.h"
#include "error.h"
#include "audio.h"
#include "renderer.h"
#include "cmath.h"

static void		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		error_msg_sdl(EIO, "Failed to init SDL");
	if (TTF_Init() < 0)
		error_msg_sdl(ENOMEM, "Failed to init TTF");
}

static void		init_general(t_game *game)
{
	SDL_Surface const	*surf = game->surface;
	char				*path;

	game->state = running;
	init_gametime(&game->starttime);
	game->cursoractive = TRUE;
	game->setting->vfov = calc_vfov(game->setting->fov, surf->w, surf->h);
	SDL_GL_SetSwapInterval(-1);
	path = ft_strformat("%s/resources/data/settings", game->exec_path);
	if (access(path, F_OK) != 0)
		mkdir(path, 0770);
	ft_strdel(&path);
	path = ft_strformat("%s/resources/data/map/custom", game->exec_path);
	if (access(path, F_OK) != 0)
		mkdir(path, 0770);
	ft_strdel(&path);
}

static t_game	*alloc_game(void)
{
	t_game	*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	if (game == NULL)
		error_msg_errno("Failed to alloc game");
	return (game);
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
	game->exec_path = ft_strndup(argv[0], path_len);
	if (game->exec_path == NULL)
		error_msg_errno("Failed to alloc doom dir");
}

t_game			*init_prerequisites(char **argv, char **envp)
{
	t_game	*game;

	init_sdl();
	game = alloc_game();
	set_basic_args(game, argv, envp);
	unpack_resources(game);
	init_settings(game);
	init_window_surface(game);
	init_eventstate(game);
	init_general(game);
	return (game);
}
