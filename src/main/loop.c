/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 15:22:13 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

#include "gui_config.h"
#include "gui.h"
#include "game.h"
#include "keymap.h"

static void		check_quit(t_game *game, SDL_Event event)
{
	if (event.type == SDL_QUIT)
		game->state = stopped;
	else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
}

static void		check_ui_click(t_game *game, SDL_Event event)
{
	if (game->cursoractive == FALSE || event.type != SDL_MOUSEBUTTONDOWN)
		return ;
	if (event.button.button & SDL_BUTTON_LEFT)
		check_gui_hit(game, (SDL_Point){event.button.x, event.button.y});
}

static void		manage_keymap(t_game *game, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		toggle_keystate(game->keymap, event.key.keysym.sym, TRUE);
	else if (event.type == SDL_KEYUP && event.key.repeat == 0)
		toggle_keystate(game->keymap, event.key.keysym.sym, FALSE);
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		toggle_keystate(game->keymap, event.button.button, TRUE);
	else if (event.type == SDL_MOUSEBUTTONUP)
		toggle_keystate(game->keymap, event.button.button, FALSE);
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKQUOTE)
		print_keymap(game->keymap);
}

void			loop(t_game *game)
{
	SDL_Event	event;

	while (game->state == running)
	{
		while (SDL_PollEvent(&event))
		{
			check_quit(game, event);
			check_ui_click(game, event);
			manage_keymap(game, event);
		}
		draw_gui(game->ui);
		SDL_UpdateWindowSurface(game->window);
	}
}
