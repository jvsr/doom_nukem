/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/09/24 17:17:21 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "game.h"
#include "init.h"

static int	destroy(t_game *game)
{
	SDL_DestroyWindow(game->window);
	SDL_Quit();
	TTF_Quit();
	exit(0);
	return (0);
}

int			main(void)
{
	t_game *game;
	t_bool isloaded;

	isloaded = TRUE;
	game = init();
	splash(game, &isloaded);
	loop(game);
	return (destroy(game));
}
