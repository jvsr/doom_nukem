/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   splash.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 16:46:17 by euan           #+#    #+#                */
/*   Updated: 2019/09/25 16:38:21 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include "tga.h"
#include "game.h"
#include "sdl_extra.h"
#include "types.h"

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
	SDL_Event		temp;
	const t_uint64	duration = 1500;

	now = get_gametime(&game->starttime);
	frametime = now;
	while (frametime - now < duration)
	{
		SDL_PollEvent(&temp);
		alpha = alpha_func((double)(frametime - now), duration);
		sdl_set_surface_alpha(splash, alpha);
		sdl_clear_surface(game->surface);
		sdl_merge_surface_alpha_scaled(game->surface, splash);
		SDL_UpdateWindowSurface(game->window);
		frametime = get_gametime(&game->starttime);
	}
	(void)temp;
}

void			splash(t_game *game, t_bool *finished, char *loc)
{
	SDL_Surface *splash;
	t_uint64	now;
	SDL_Event	temp;

	sdl_clear_surface(game->surface);
	splash = open_tga_sdl(loc);
	sdl_set_surface_alpha(splash, 0);
	fade(game, splash, fadein);
	now = get_gametime(&game->starttime);
	while (*finished == FALSE || get_gametime(&game->starttime) - now < 3000)
		SDL_PollEvent(&temp);
	fade(game, splash, fadeout);
	SDL_FreeSurface(splash);
	(void)temp;
}