/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 13:33:35 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "gui.h"

static void		polled(t_game *game, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		game->state = stopped;
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
	else if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button
		& SDL_BUTTON_LEFT)
		clickcheck(game);
}

void			loop(t_game *game)
{
	SDL_Event event;

	game->ui.redraw = TRUE;
	while (game->state == running)
	{
		SDL_FillRect(game->surface, NULL, 0);
		while (SDL_PollEvent(&event))
			polled(game, &event);
		drawgui(game);
		SDL_UpdateWindowSurface(game->window);
	}
}
