/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 17:43:38 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include "gui.h"
#include "game.h"

static void		polled(t_game *game, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		game->state = stopped;
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
	else if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button
		& SDL_BUTTON_LEFT)
		checkclick(game, (SDL_Point){event->button.x, event->button.y});
}

void			loop(t_game *game)
{
	SDL_Event event;

	game->ui.redraw = TRUE;
	t_image *image = newimagecolour(&((t_guiinfo){"image", TRUE, 
	(t_coord){0.2, 0.2}, (t_coord){0.2, 0.2}}), (SDL_Color){255, 255, 255, 255});
	settransformparent(&image->transform, &game->ui.transform);
	while (game->state == running)
	{
		SDL_FillRect(game->surface, NULL, 0);
		while (SDL_PollEvent(&event))
			polled(game, &event);
		drawgui(game);
		SDL_UpdateWindowSurface(game->window);
	}
}
