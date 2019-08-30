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

#include "keymap.h"

static void		checkquit(t_game *game, SDL_Event event)
{
	if (event.type == SDL_QUIT)
		game->state = stopped;
	else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
}

static void		keymap(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		keymaptoggle(game->keymap, event.key.keysym.sym, TRUE);
	else if (event.type == SDL_KEYUP && event.key.repeat == 0)
		keymaptoggle(game->keymap, event.key.keysym.sym, FALSE);
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		keymaptoggle(game->keymap, event.button.button, TRUE);
	else if (event.type == SDL_MOUSEBUTTONUP)
		keymaptoggle(game->keymap, event.button.button, FALSE);
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
		keymapprint(game->keymap);
}

void			loop(t_game *game)
{
	SDL_Event event;

	// keymaptoggle(game->keymap, SDLK_SPACE, TRUE);
	// keymapprint(game->keymap);
	// keymaptoggle(game->keymap, SDLK_SPACE, FALSE);
	// keymapprint(game->keymap);
	while (game->state == running)
	{
		while (SDL_PollEvent(&event))
		{
			checkquit(game, event);
			keymap(game, event);
		}
		keymapprint(game->keymap);
		SDL_Delay(100);
		SDL_UpdateWindowSurface(game->window);
	}
}
