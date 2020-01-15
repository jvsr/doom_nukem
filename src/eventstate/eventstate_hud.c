/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:13:29 by jvisser        #+#    #+#                */
/*   Updated: 2020/01/14 12:23:30 by jvisser       ########   odam.nl         */
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
#include "rinfo.h"
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
	tmp = ((float)mouse_pos.x * game->setting->sensitivity * PLAYER_H_SENSE);
	player->angle = wrap_float(player->angle + tmp, 0, 360.0);
	player->updown = clamp_float(player->updown -
		((float)mouse_pos.y * pow(game->setting->sensitivity, 2) * PLAYER_V_SENSE),
		PLAYER_UPDOWN_MIN, PLAYER_UPDOWN_MAX);
	player->mag.cos = cos(player->angle * PI_R);
	player->mag.sin = sin(player->angle * PI_R);
	SDL_WarpMouseInWindow(game->window, game->surface->w / 2,
		game->surface->h / 2);
}

void		hud_eventstate(t_game *game, SDL_Event event)
{
	(void)game;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
	{
		set_mouse_capture();
		// different behaviour to be implemented, real main menu as placeholder
		if (SDL_GetRelativeMouseMode() == SDL_FALSE)
		{
			set_elem_show_clickable(get_gui_child(game->ui, "mainmenu"), TRUE);
			set_elem_show_clickable(get_gui_child(game->ui, "hud"), FALSE);
			game->cureventstate->eventstate = mainmenu;
		}
	}
	if (event.type == SDL_MOUSEMOTION)
		manage_player_angle(game);
}
