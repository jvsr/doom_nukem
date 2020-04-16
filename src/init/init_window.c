/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:52:36 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:46:19 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "tga.h"
#include "game.h"
#include "error.h"
#include "setting.h"

static uint32_t	create_window_flags(t_setting *setting)
{
	uint32_t	flags;

	flags = 0;
	flags |= SDL_WINDOW_ALLOW_HIGHDPI;
	flags |= SDL_WINDOW_MOUSE_FOCUS;
	if (setting->resolution_type == borderless)
		flags |= SDL_WINDOW_BORDERLESS;
	else if (setting->resolution_type == fullscreen)
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	return (flags);
}

void			init_window_surface(t_game *game)
{
	const uint32_t	flags = create_window_flags(game->setting);
	SDL_Surface		*window_icon;

	window_icon = open_tga_sdl("splash/icon", game->exec_path);
	game->window = SDL_CreateWindow("Doom Nukem",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		game->setting->resolution.x,
		game->setting->resolution.y,
		flags);
	if (game->window == NULL)
		error_msg_sdl(ENOMEM, "Failed to alloc game window");
	game->surface = SDL_GetWindowSurface(game->window);
	if (game->surface == NULL)
		error_msg_sdl(ENOMEM, "Failed to alloc game surface");
	SDL_SetWindowIcon(game->window, window_icon);
	SDL_FreeSurface(window_icon);
}
