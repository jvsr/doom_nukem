/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 15:27:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>

#include "libft/ft_memory.h"

#include "game.h"
#include "init.h"
#include "error.h"

static void		init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		error_msg(SDL_GetError(), 1);
}

static t_game	*alloc_game(void)
{
	t_game	*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	if (game == NULL)
		error_msg(strerror(errno), errno);
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
		error_msg(SDL_GetError(), 1);
	game->surface = SDL_GetWindowSurface(game->window);
}

static void		init_game(t_game *game)
{
	game->state = running;
}

t_game			*init(void)
{
	t_game *game;

	init_sdl();
	game = alloc_game();
	init_window_surface(game);
	init_game(game);
	return (game);
}
