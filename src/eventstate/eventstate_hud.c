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
	SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
	tmp = ((float)((float)mouse_pos.x - (game->surface->w / 2)) / game->surface->w)
		* 60.0 * game->setting->sensitivity;
	player->angle = wrap_float(player->angle + tmp, 0, 360.0);
	player->mag.cos = cosf(player->angle * PI_R);
	player->mag.sin = sinf(player->angle * PI_R);
	ft_memcpy(&player->mag, &(t_coord){wrap_float(player->angle -
		(game->setting->fov / 2), 0.0, 360.0), wrap_float(player->angle +
		(game->setting->fov / 2), 0.0, 360.0)}, sizeof(t_coord));
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
