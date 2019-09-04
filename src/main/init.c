/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/04 13:26:39 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <errno.h>
#include "libft/ft_memory.h"
#include "libft/ft_string.h"
#include "game.h"
#include "init.h"
#include "error.h"
#include "gui.h"

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
	game->ui.font[0] = TTF_OpenFont("fonts/Roboto-Regular.ttf", 50);
	game->ui.font[1] = TTF_OpenFont("fonts/monof55.ttf", 50);
	game->ui.transform.name = ft_strdup(GUI_NAME);
	game->ui.transform.visible = TRUE;
	return (game);
}

static	void	init_window_surface(t_game *game)
{
	game->window = SDL_CreateWindow("Doom Nukem", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, INITWIDTH, INITHEIGHT, SDL_WINDOW_ALLOW_HIGHDPI |
		SDL_WINDOW_MOUSE_FOCUS);
	if (game->window == NULL)
		error_msg(SDL_GetError(), 1);
	game->surface = SDL_GetWindowSurface(game->window);
	game->ui.guisurface = SDL_CreateRGBSurface(0, game->surface->w,
		game->surface->h, 32, 0, 0, 0, 0);
	game->ui.onclicks = NULL;
}

static void		init_game(t_game *game)
{
	game->state = running;
}

t_game			*init(void)
{
	t_game *game;

	init_sdl();
	TTF_Init();
	game = alloc_game();
	init_window_surface(game);
	init_game(game);
	return (game);
}
