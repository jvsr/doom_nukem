/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   splash.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 16:46:17 by euan           #+#    #+#                */
/*   Updated: 2019/09/24 17:45:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include "tga.h"
#include "game.h"
#include "sdl_extra.h"
#include "types.h"

void	fadeout(t_game *game, SDL_Surface *splash)
{
	t_uint8		alpha;
	t_uint64	now;
	t_uint64	frametime;

	now = get_gametime(&game->starttime);
	frametime = now;
	while (frametime - now < 2000)
	{
		SDL_PollEvent(NULL);
		if (frametime - now == 0)
			alpha = 255;
		else
			alpha = 255 * (1.0 - ((double) (frametime - now) / 2000));
		sdl_set_surface_alpha(splash, alpha);
		sdl_clear_surface(game->surface);
		sdl_merge_surface_alpha_scaled(game->surface, splash);
		SDL_UpdateWindowSurface(game->window);
		frametime = get_gametime(&game->starttime);
	}
}

void	fadein(t_game *game, SDL_Surface *splash)
{
	t_uint8		alpha;
	t_uint64	now;
	t_uint64	frametime;

	now = get_gametime(&game->starttime);
	frametime = now;
	while (frametime - now < 2000)
	{
		SDL_PollEvent(NULL);
		if (frametime - now == 0)
			alpha = 0;
		else
			alpha = 255 * ((double) (frametime - now) / 2000);
		sdl_set_surface_alpha(splash, alpha);
		sdl_clear_surface(game->surface);
		sdl_merge_surface_alpha_scaled(game->surface, splash);
		SDL_UpdateWindowSurface(game->window);
		frametime = get_gametime(&game->starttime);
	}
}

void	splash(t_game *game, t_bool *finished)
{
	SDL_Surface *splash;
	t_uint64	now;
	
	sdl_clear_surface(game->surface);
	splash = open_tga_sdl("splash/splash");
	sdl_set_surface_alpha(splash, 0);
	fadein(game, splash);
	now = get_gametime(&game->starttime);
	while (*finished == FALSE || get_gametime(&game->starttime) - now < 2000);
	fadeout(game, splash);
	SDL_FreeSurface(splash);
}