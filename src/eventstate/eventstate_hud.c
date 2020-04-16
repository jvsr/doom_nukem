/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_hud.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:13:29 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/16 14:59:47 by euan          ########   odam.nl         */
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

static void	manage_player_angle(t_game *game, t_bool *skip)
{
	t_player	*player;
	SDL_Point	mouse_pos;
	float		tmp;

	if (!SDL_GetRelativeMouseMode())
		return ;
	SDL_GetRelativeMouseState(&mouse_pos.x, &mouse_pos.y);
	if (*skip == TRUE)
	{
		*skip = FALSE;
		return ;
	}
	player = game->player;
	tmp = ((float)mouse_pos.x * game->setting->sensitivity * PLAYER_H_SENSE);
	player->angle = wrap_float(player->angle + tmp, 0, 360.0);
	player->updown = clamp_float(player->updown - ((float)mouse_pos.y
		* pow(game->setting->sensitivity, 2) * PLAYER_V_SENSE),
		PLAYER_UPDOWN_MIN, PLAYER_UPDOWN_MAX);
	player->mag.cos = cos(player->angle * PI_R);
	player->mag.sin = sin(player->angle * PI_R);
}

static void	enter_options(t_game *game, t_bool *skip)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudOptionsOverlay"), TRUE);
	set_elem_show_clickable(get_gui_child(game->ui, "hudOptionsMenu"), TRUE);
	set_hudsensitivity(game->setting, get_gui_child(game->ui, "hudOptions"));
	set_hudmusic(game->setting, get_gui_child(game->ui, "hudVolume"));
	set_hudsound(game->setting, get_gui_child(game->ui, "hudVolume"));
	set_hudfov(game->setting, get_gui_child(game->ui, "hudFov"), game->surface);
	game->cureventstate->eventstate = hud_options;
	*skip = TRUE;
}

static void	manage_keydown(t_game *game,
									SDL_Event event, t_bool *skip_mouse_move)
{
	if (!game->player->is_dead && event.key.keysym.sym == SDLK_ESCAPE)
		enter_options(game, skip_mouse_move);
	else if (is_helddown(game->keymap, SDLK_F6)
		&& event.key.keysym.sym == SDLK_f)
		game->player->is_flying = !game->player->is_flying;
	else if (is_helddown(game->keymap, game->setting->controls.interact))
		click_on_door(game->player, game);
	else if (event.key.keysym.sym == SDLK_F10)
		SDL_SetRelativeMouseMode(!SDL_GetRelativeMouseMode());
	else if (event.key.keysym.sym == SDLK_UP)
		game->player->updown = clamp_float(game->player->updown + 0.1,
		PLAYER_UPDOWN_MIN, PLAYER_UPDOWN_MAX);
	else if (event.key.keysym.sym == SDLK_DOWN)
		game->player->updown = clamp_float(game->player->updown - 0.1,
		PLAYER_UPDOWN_MIN, PLAYER_UPDOWN_MAX);
	else if (event.key.keysym.sym == SDLK_LEFT)
		game->player->angle = wrap_float(game->player->angle - 7.5, 0, 360.0);
	else if (event.key.keysym.sym == SDLK_RIGHT)
		game->player->angle = wrap_float(game->player->angle + 7.5, 0, 360.0);
	else if (event.key.keysym.sym == game->setting->controls.shoot)
		player_shoot(game, game->player);
	game->player->mag.cos = cos(game->player->angle * PI_R);
	game->player->mag.sin = sin(game->player->angle * PI_R);
}

void		hud_eventstate(t_game *game, SDL_Event event)
{
	static t_bool	skip_mouse_move = TRUE;

	if (event.key.keysym.sym == game->setting->controls.crouch)
	{
		if (event.type == SDL_KEYDOWN)
			game->player->player_height = PLAYER_CROUCH;
		else if (event.type == SDL_KEYUP
		&& game->map->sectors[game->player->cur_sector].ceil
		> game->player->height + (PLAYER_HEIGHT - PLAYER_CROUCH))
			game->player->player_height = PLAYER_HEIGHT;
	}
	game->player->height = game->player->player_height
	+ game->map->sectors[game->player->cur_sector].floor;
	if (event.type == SDL_MOUSEMOTION)
		manage_player_angle(game, &skip_mouse_move);
	if (event.type == SDL_KEYDOWN)
		manage_keydown(game, event, &skip_mouse_move);
	if (event.type == SDL_MOUSEBUTTONDOWN &&
		event.button.button == game->setting->controls.shoot &&
		skip_mouse_move == FALSE)
		player_shoot(game, game->player);
	else
		skip_mouse_move = FALSE;
}
