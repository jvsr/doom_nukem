/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/27 15:38:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		polled(t_game *game, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		game->state = stopped;
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
}

void			loop(t_game *game)
{
	SDL_Event event;

	while (game->state == running)
	{
		while (SDL_PollEvent(&event))
			polled(game, &event);
		SDL_UpdateWindowSurface(game->window);
	}
}
