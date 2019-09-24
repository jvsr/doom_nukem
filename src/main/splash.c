/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   splash.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 16:46:17 by euan           #+#    #+#                */
/*   Updated: 2019/09/24 16:46:17 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include "tga.h"
#include "game.h"
#include "sdl_extra.h"
#include "types.h"

void	splash(t_game *game, t_bool *finished)
{
	SDL_Surface *splash;
	t_uint8		alpha;
	t_uint64	now;
	t_uint64	frametime;
	
	splash = open_tga_sdl("resources/textures/splash.tga");
	sdl_merge_surface_scaled(game->surface, splash);
	SDL_UpdateWindowSurface(game->window);
	while (*finished == FALSE);
	now = get_gametime(&game->starttime);
	frametime = now;
	while (frametime - now < 2000)
	{
		if (frametime - now == 0)
			alpha = 255;
		else
			alpha = 255 * (1.0 - ((double) (frametime - now) / 2000));
		sdl_set_surface_alpha(splash, alpha);
		sdl_clear_surface(game->surface);
		frametime = get_gametime(&game->starttime);
	}
}