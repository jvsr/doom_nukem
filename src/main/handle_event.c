/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_event.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:19:37 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:49:47 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "eventstate.h"
#include "eventstate_transition_table.h"
#include "audio.h"

void			check_quit(t_game *game, SDL_Event event)
{
	if (event.type == SDL_QUIT)
		game->state = stopped;
}

static void		check_ui_click(t_game *game, SDL_Event event)
{
	t_transform	*hit;

	if (game->cursoractive == FALSE || event.type != SDL_MOUSEBUTTONDOWN)
		return ;
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		hit = check_gui_hit(game, (SDL_Point){event.button.x, event.button.y});
		if (hit != NULL && hit->onclick != NULL)
		{
			play_sound(game->audio_man, "button_ui");
			hit->onclick(game, hit);
		}
	}
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

void			handle_event(t_game *game, SDL_Event event)
{
	void		(*eventstate_fnc)(t_game*, SDL_Event);

	check_quit(game, event);
	check_ui_click(game, event);
	manage_keymap(game, event);
	eventstate_fnc = g_eventstate[game->cureventstate->eventstate];
	eventstate_fnc(game, event);
}
