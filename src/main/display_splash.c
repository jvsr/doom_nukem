/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_splash.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 16:46:17 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:49:36 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_thread.h>

#include "tga.h"
#include "game.h"
#include "types.h"
#include "sdl_extra.h"
#include "eventstate.h"

static t_uint8	fadeout(t_uint64 val, t_uint64 duration)
{
	if (val != 0)
		return (255 * (1.0 - ((double)(val) / duration)));
	else
		return (255);
}

static t_uint8	fadein(t_uint64 val, t_uint64 duration)
{
	if (val != 0)
		return (255 * ((double)(val) / duration));
	else
		return (0);
}

static void		fade(t_game *game, SDL_Surface *splash,
					t_uint8 (*alpha_func)(t_uint64, t_uint64))
{
	t_uint8			alpha;
	t_uint64		now;
	t_uint64		frametime;
	const t_uint64	duration = 1500;

	now = get_gametime(&game->starttime);
	frametime = now;
	while (game->state == running && frametime - now < duration)
	{
		alpha = alpha_func((double)(frametime - now), duration);
		sdl_set_surface_alpha(splash, alpha);
		SDL_LockMutex(game->cureventstate->lock);
		game->cureventstate->arguments->dgt = TRUE;
		sdl_clear_surface(game->surface);
		sdl_merge_surface_alpha_scaled(game->surface, splash);
		SDL_UnlockMutex(game->cureventstate->lock);
		frametime = get_gametime(&game->starttime);
	}
}

void			*display_splash(t_game *game, char *loc)
{
	t_types		update_window;
	SDL_Surface *splashscreen;
	t_uint64	now;

	update_window.dgt = FALSE;
	game->cureventstate->arguments = &update_window;
	sdl_clear_surface(game->surface);
	splashscreen = open_tga_sdl(loc, game->exec_path);
	sdl_set_surface_alpha(splashscreen, 0);
	fade(game, splashscreen, fadein);
	now = get_gametime(&game->starttime);
	while (game->cureventstate->eventstate == initload
	|| get_gametime(&game->starttime) - now < 1800)
		;
	fade(game, splashscreen, fadeout);
	SDL_FreeSurface(splashscreen);
	game->cureventstate->eventstate = mainmenu;
	SDL_LockMutex(game->cureventstate->lock);
	game->cureventstate->arguments = NULL;
	SDL_UnlockMutex(game->cureventstate->lock);
	return (NULL);
}
