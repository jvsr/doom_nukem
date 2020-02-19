/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/19 21:33:05 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

#include "libft/ft_char.h"
#include "libft/ft_printf.h"

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

static void		load_info(t_game *game)
{
	SDL_Event event;

	sdl_run_thread(NULL, sdl_new_ttask(init_function, 0, 1, game));
	sdl_run_thread(NULL, sdl_new_ttask(display_splash, 0, 2, game,
		"splash/splash"));
	while (game->state == running
	&& (game->cureventstate->eventstate == initload
	|| game->cureventstate->eventstate == splash))
	{
		while (SDL_PollEvent(&event))
			check_quit(game, event);
	}
}

static void		init_frames(t_game *game, int *framecount,
							t_uint64 *lastsecond, t_uint64 *lastframe)
{
	*framecount = 0;
	*lastsecond = get_gametime(&game->starttime);
	*lastframe = *lastsecond;
	game->frametime = PLAYER_MOVE_BASE_FPS;
}

static void		handle_frames(t_game *game, int *framecount,
							t_uint64 *lastsecond, t_uint64 *lastframe)
{
	if (get_gametime(&game->starttime) - *lastsecond >= 1000)
	{
		ft_printf("FPS %d\n", *framecount);
		game->frametime = *framecount;
		*framecount = 0;
		*lastsecond = get_gametime(&game->starttime);
	}
	(*framecount)++;
	game->lastframe = get_gametime(&game->starttime) - *lastframe;
	*lastframe = get_gametime(&game->starttime);
}

void			loop(t_game *game)
{
	SDL_Event	event;
	int			framecount;
	t_uint64	lastsecond;
	t_uint64	lastframe;

	load_info(game);
	if (game->state != running)
		return ;
	init_frames(game, &framecount, &lastsecond, &lastframe);
	fade_in_music(game->audio_man, TITLE_SONG, 3500);
	while (game->state == running)
	{
		while (SDL_PollEvent(&event))
			handle_event(game, event);
		loop_core(game, game->cureventstate->eventstate);
		draw_gui(game->ui, game);
		SDL_UpdateWindowSurface(game->window);
		handle_frames(game, &framecount, &lastsecond, &lastframe);
	}
}
