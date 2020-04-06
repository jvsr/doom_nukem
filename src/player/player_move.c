/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:47:55 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:18 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <limits.h>
#include <SDL2/SDL_keycode.h>

#include "libft/ft_str.h"

#include "game.h"
#include "rinfo.h"
#include "setting.h"
#include "cmath.h"
#include "player.h"
#include "keymap.h"

static void		set_speed(t_game *game, float *speed)
{
	if (game->player->player_height == PLAYER_CROUCH)
		*speed = PLAYER_CROUCH_SPEED;
	else if (is_helddown(game->keymap, SDLK_LSHIFT))
		*speed = PLAYER_RUN_SPEED;
	else
		*speed = PLAYER_MOVE_SPEED;
}

static void		determine_movement(t_game *game, t_bool *draw, float speed,
									t_vec *move)
{
	if (is_helddown(game->keymap, game->setting->controls.forward))
		*draw |= move_forward(game->player, speed, &move->x, &move->y);
	if (is_helddown(game->keymap, game->setting->controls.backward))
		*draw |= move_backward(game->player, speed, &move->x, &move->y);
	if (is_helddown(game->keymap, game->setting->controls.left))
		*draw |= move_left(game->player, speed, &move->x, &move->y);
	if (is_helddown(game->keymap, game->setting->controls.right))
		*draw |= move_right(game->player, speed, &move->x, &move->y);
}

static t_bool	handle_fly(t_game *game, t_bool *jump)
{
	if (is_helddown(game->keymap, game->setting->controls.jump))
		return (fly_up(game, game->player, jump));
	else if (is_helddown(game->keymap, game->setting->controls.crouch))
		return (fly_down(game, game->player, jump));
	return (FALSE);
}

static t_bool	handle_jump(t_game *game, t_bool *jump)
{
	if (game->player->heightoffset > 0 && *jump == FALSE)
		return (move_down(game, game->player, jump));
	if ((is_helddown(game->keymap, game->setting->controls.jump)
	&& game->player->heightoffset == 0 && *jump == FALSE) || *jump == TRUE)
		return (move_jump(game, game->player, jump));
	return (FALSE);
}

t_bool			player_move(t_game *game)
{
	t_bool			draw;
	float			speed;
	t_vec			move;
	static t_bool	jump = FALSE;

	draw = FALSE;
	move.x = 0;
	move.y = 0;
	set_speed(game, &speed);
	determine_movement(game, &draw, speed, &move);
	if (game->player->is_flying)
		draw |= handle_fly(game, &jump);
	else
		draw |= handle_jump(game, &jump);
	move.x = lerp_max(0, move.x,
			(float)game->lastframe / BASE_FRAME_TIME, INFINITY);
	move.y = lerp_max(0, move.y,
			(float)game->lastframe / BASE_FRAME_TIME, INFINITY);
	if (draw == TRUE)
		player_col(game, move.x, move.y);
	if (game->map->sectors[game->player->cur_sector].has_slope)
		game->player->height = player_slope(game->player,
			&game->map->sectors[game->player->cur_sector], &game->player->pos);
	return (draw);
}
