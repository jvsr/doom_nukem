/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/28 14:57:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

#include "libft/ft_char.h"

#include "gui.h"
#include "game.h"
#include "player.h"
#include "init.h"
#include "loop.h"
#include "audio.h"
#include "keymap.h"
#include "renderer.h"
#include "eventstate.h"
#include "sdl_thread.h"
#include "eventstate_transition_table.h"

static void		check_quit(t_game *game, SDL_Event event)
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
			hit->onclick(game, hit);
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
	
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
	{
		game->player->height += 0.1;
		set_elem_redraw(get_gui_child(game->ui, "gameview"));
	}
}

static void		load_info(t_game *game)
{
	SDL_Event event;

	sdl_new_thread(NULL, init_function, 1, game);
	sdl_new_thread(NULL, display_splash, 2, game, "splash/splash");
	while (game->state == running
	&& (game->cureventstate->eventstate == initload
	|| game->cureventstate->eventstate == splash))
	{
		while (SDL_PollEvent(&event))
			check_quit(game, event);
	}
}

void			loop(t_game *game)
{
	SDL_Event	event;
	void		(*eventstate_fnc)(t_game*, SDL_Event);

	load_info(game);
	fade_in_music(game->audio_man, TITLE_SONG, 3500);
	game->player->pos.x = 0;
	game->player->pos.y = 0;
	game->player->cur_sector = 0;
	game->player->height = 6;
	game->player->mag = (t_mag){cosf(0), sinf(0)};
	while (game->state == running)
	{
		while (SDL_PollEvent(&event))
		{
			check_quit(game, event);
			check_ui_click(game, event);
			manage_keymap(game, event);
			eventstate_fnc = g_eventstate[game->cureventstate->eventstate];
			eventstate_fnc(game, event);
		}
		loop_core(game, game->cureventstate->eventstate);
		draw_gui(game->ui, game);
		SDL_UpdateWindowSurface(game->window);
	}
}
