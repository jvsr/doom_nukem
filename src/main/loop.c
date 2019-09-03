/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/03 13:55:51 by pholster      ########   odam.nl         */
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
		toggle_keymap(game->keymap, event.key.keysym.sym, TRUE);
	else if (event.type == SDL_KEYUP && event.key.repeat == 0)
		toggle_keymap(game->keymap, event.key.keysym.sym, FALSE);
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		toggle_keymap(game->keymap, event.button.button, TRUE);
	else if (event.type == SDL_MOUSEBUTTONUP)
		toggle_keymap(game->keymap, event.button.button, FALSE);
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKQUOTE)
		print_keymap(game->keymap);
}

void			loop(t_game *game)
{
	SDL_Event event;

	while (game->state == running)
	{
		while (SDL_PollEvent(&event))
		{
			checkquit(game, event);
			keymap(game, event);
		}
		SDL_UpdateWindowSurface(game->window);
	}
}
