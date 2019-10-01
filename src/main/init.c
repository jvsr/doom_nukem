/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/25 13:00:07 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_mem.h"

#include "game.h"
#include "init.h"
#include "error.h"
#include "gametime.h"
#include "audio.h"

static void		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		error_msg(SDL_GetError(), 1, "Failed to init SDL");
	if (TTF_Init() < 0)
		error_msg(SDL_GetError(), 1, "Failed to init TTF");
}

static t_game	*alloc_game(void)
{
	t_game	*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	if (game == NULL)
		error_msg(strerror(errno), errno, "Failed to alloc game");
	return (game);
}

static	void	init_window_surface(t_game *game)
{
	game->window = SDL_CreateWindow("Doom Nukem",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		INIT_WIDTH,
		INIT_HEIGHT,
		SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_MOUSE_FOCUS);
	if (game->window == NULL)
		error_msg(SDL_GetError(), 1, "Failed to alloc game window");
	game->surface = SDL_GetWindowSurface(game->window);
}

static void		init_game(t_game *game)
{
	game->state = running;
	init_gametime(&game->starttime);
	game->cursoractive = TRUE;
}

t_game			*init(void)
{
	t_game *game;

	init_sdl();
	game = alloc_game();
	init_window_surface(game);
	init_game(game);
	init_audio(game);
	init_gui(game);
	init_keymap(game);
	return (game);
}
