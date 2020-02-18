/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:13:29 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/18 17:22:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_stdinc.h>

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

// static void	set_mouse_capture(void)
// {
// 	static int	caught = TRUE;

// 	SDL_SetRelativeMouseMode(caught);
// 	caught = !caught;
// }

static void	manage_player_angle(t_game *game, t_bool skip)
{
	t_player	*player;
	t_point		mouse_pos;
	float		tmp;

	if (!SDL_GetRelativeMouseMode())
		return ;
	SDL_GetRelativeMouseState(&mouse_pos.x, &mouse_pos.y);
	if (skip == TRUE)
		return ;
	player = game->player;
	tmp = ((float)mouse_pos.x * game->setting->sensitivity * PLAYER_H_SENSE);
	player->angle = wrap_float(player->angle + tmp, 0, 360.0);
	player->updown = clamp_float(player->updown -
		((float)mouse_pos.y * pow(game->setting->sensitivity, 2) * PLAYER_V_SENSE),
		PLAYER_UPDOWN_MIN, PLAYER_UPDOWN_MAX);
	player->mag.cos = cos(player->angle * PI_R);
	player->mag.sin = sin(player->angle * PI_R);
}

void		hud_eventstate(t_game *game, SDL_Event event)
{
	static t_bool	skip_mouse_move = TRUE;

	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == game->setting->controls.crouch)
		game->player->player_height = PLAYER_CROUCH;
	else if (event.type == SDL_KEYUP && event.key.keysym.sym == game->setting->controls.crouch
	&& game->map->sectors[game->player->cur_sector].ceil > game->player->height + (PLAYER_HEIGHT - PLAYER_CROUCH))
		game->player->player_height = PLAYER_HEIGHT;
	game->player->height = game->player->player_height + game->map->sectors[game->player->cur_sector].floor;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
		set_elem_show_clickable(get_gui_child(game->ui, "hudoptionsoverlay"), TRUE);
		set_elem_show_clickable(get_gui_child(game->ui, "hudoptionsmenu"), TRUE);
		set_hudsensitivity(game->setting, get_gui_child(game->ui, "hudoptions"));
		game->cureventstate->eventstate = hud_options;
	}
	if (event.type == SDL_KEYDOWN && is_helddown(game->keymap, SDLK_F6) && event.key.keysym.sym == SDLK_f)
		game->player->is_flying = !game->player->is_flying;
	if (event.type == SDL_MOUSEMOTION)
	{
		manage_player_angle(game, skip_mouse_move);
		skip_mouse_move = FALSE;
	}
}
