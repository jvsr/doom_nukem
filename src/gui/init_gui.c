/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_gui.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 20:21:45 by pholster       #+#    #+#                */
/*   Updated: 2019/09/10 20:21:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL_ttf.h>

#include "gui.h"
#include "game.h"
#include "error.h"

void	init_gui(t_game *game)
{
	game->ui.guisurface = SDL_CreateRGBSurface(0, game->surface->w,
		game->surface->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	if (game->window == NULL)
		error_msg(SDL_GetError(), 1);
	game->cursoractive = TRUE;
	game->ui.onclicks = NULL;
	game->ui.font[0] = TTF_OpenFont("fonts/Roboto-Regular.ttf", 50);
	game->ui.font[1] = TTF_OpenFont("fonts/monof55.ttf", 50);
	game->ui.font[2] = TTF_OpenFont("fonts/ka1.ttf", 50);
	game->ui.transform.name = ft_strdup(GUI_NAME);
	game->ui.transform.visible = TRUE;
}
