/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/24 13:51:37 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

#include "gui_config.h" //
#include "gui.h"
#include "game.h"

static void		polled(t_game *game, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		game->state = stopped;
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
	else if (game->cursoractive && event->type == SDL_MOUSEBUTTONDOWN
	&& event->button.button & SDL_BUTTON_LEFT)
		check_gui_hit(game, (SDL_Point){event->button.x, event->button.y});
}

void			loop(t_game *game)
{
	SDL_Event	event;

	while (game->state == running)
	{
		SDL_FillRect(game->surface, NULL, 0);
		while (SDL_PollEvent(&event))
			polled(game, &event);
		draw_gui(game->ui);
		SDL_UpdateWindowSurface(game->window);
	}
}
