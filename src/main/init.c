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
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_mem.h"

#include "game.h"
#include "setting.h"
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

void			init_eventstate(t_game *game)
{
	t_eventstate	*cureventstate;

	cureventstate = ft_memalloc(sizeof(t_eventstate));
	if (cureventstate == NULL)
		error_msg_errno("Failed to alloc eventstate");
	cureventstate->eventstate = mainmenu;
	cureventstate->arguments = NULL;
	game->cureventstate = cureventstate;
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
	init_eventstate(game);
	return (game);
}
