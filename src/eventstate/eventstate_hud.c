/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:13:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 17:25:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>

#include "gui.h"
#include "game.h"
#include "cmath.h"
#include "player.h"
#include "keymap.h"
#include "setting.h"
#include "onclick.h"
#include "eventstate.h"
#include "libft/ft_mem.h"

static void set_mouse_capture()
{
	static int caught = TRUE;

	SDL_SetRelativeMouseMode(caught);
	caught = !caught;
}

static void	manage_player_angle(t_game *game)
{
	t_player	*player;
	t_point		mouse_pos;
	float		tmp;

	if (!SDL_GetRelativeMouseMode())
		return ;
	player = game->player;
	SDL_GetRelativeMouseState(&mouse_pos.x, &mouse_pos.y);
	tmp = (float)mouse_pos.x * game->setting->sensitivity * 0.2;
	player->angle = wrap_float(player->angle + tmp, 0, 360.0);
	player->mag.cos = cosf(player->angle);
	player->mag.sin = sinf(player->angle);
	SDL_WarpMouseInWindow(game->window, game->surface->w / 2,
		game->surface->h / 2);
}

void		hud_eventstate(t_game *game, SDL_Event event)
{
	(void)game;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		set_mouse_capture();
	if (event.type == SDL_MOUSEMOTION)
		manage_player_angle(game);
}
