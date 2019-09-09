/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/09/09 15:25:13 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

#include "game.h"
#include "init.h"

static int	destroy(t_game *game)
{
	SDL_DestroyWindow(game->window);
	SDL_Quit();
	return (1);
}

int			main(void)
{
	t_game *game;

	game = init();
	loop(game);
	return (destroy(game));
}
