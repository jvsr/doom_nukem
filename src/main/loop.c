/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 14:17:20 by ehollidg      ########   odam.nl         */
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
}

void			loop(t_game *game)
{
	SDL_Event event;
	TTF_Font *font = TTF_OpenFont("fonts/ALHAMBRA.TTF",  25);
	SDL_BlitSurface(TTF_RenderText_Solid(font, "Ha, Gay!",
		(SDL_Color){255, 255, 255, 255}), &(SDL_Rect){20, 20, 100, 100}, game->surface, &(SDL_Rect){20, 20, 100, 100});
	while (game->state == running)
	{
		while (SDL_PollEvent(&event))
			polled(game, &event);
		SDL_UpdateWindowSurface(game->window);
	}
}
