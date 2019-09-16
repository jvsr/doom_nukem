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

#include <SDL2/SDL_ttf.h>

#include "libft/ft_string.h"

#include "gui.h"
#include "game.h"
#include "error.h"

static void	init_fonts(t_game *game)
{
	game->ui.fonts[0] = TTF_OpenFont("fonts/Roboto-Regular.ttf", 50);
	game->ui.fonts[1] = TTF_OpenFont("fonts/monof55.ttf", 50);
	game->ui.fonts[2] = TTF_OpenFont("fonts/ka1.ttf", 50);
}

void	init_gui(t_game *game)
{
	game->ui.window_surface = game->surface;
	game->ui.children = NULL;
	init_fonts(game);
}
