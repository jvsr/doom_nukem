/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:47:55 by pholster       #+#    #+#                */
/*   Updated: 2020/01/18 15:12:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <SDL2/SDL_keycode.h>

#include "libft/ft_str.h"

#include "game.h"
#include "setting.h"
#include "cmath.h"
#include "player.h"
#include "keymap.h"

static t_bool	move_forward(t_player *player, float speed, float *xspeed, float *yspeed)
{
	*xspeed += speed * cosf(player->angle * PI_R);
	*yspeed += speed * sinf(player->angle * PI_R);
	return (TRUE);
}

static t_bool	move_backward(t_player *player, float speed, float *xspeed, float *yspeed)
{
	*xspeed += -(speed * cos(player->angle * PI_R));
	*yspeed += -(speed * sin(player->angle * PI_R));
	return (TRUE);
}

static t_bool	move_left(t_player *player, float speed, float *xspeed, float *yspeed)
{
	*xspeed += speed * sin(player->angle * PI_R);
	*yspeed += -(speed * cos(player->angle * PI_R));
	return (TRUE);
}

static t_bool	move_right(t_player *player, float speed, float *xspeed, float *yspeed)
{
	*xspeed += -(speed * sin(player->angle * PI_R));
	*yspeed += speed * cos(player->angle * PI_R);
	return (TRUE);
}

static t_bool	move_jump(t_player *player, size_t *jump)
{
	(*jump)++;
	if (*jump > PLAYER_JUMP_FRAMES / 2)
		player->heightoffset -= PLAYER_JUMP
			* (pow(((double)(*jump)
			- (PLAYER_JUMP_FRAMES / 2)) / PLAYER_JUMP_FRAMES, 2));
	else if (*jump - 1 <= PLAYER_JUMP_FRAMES / 2)
		player->heightoffset += PLAYER_JUMP
			* (pow(((double)(PLAYER_JUMP_FRAMES / 2)
			- (*jump - 1)) / PLAYER_JUMP_FRAMES, 2));
	if (*jump == PLAYER_JUMP_FRAMES)
		*jump = 0;
	return (TRUE);
}

t_bool			player_move(t_game *game)
{
	t_bool			draw;
	float			speed;
	float			xspeed;
	float			yspeed;
	static size_t	jump = 0;

	draw = FALSE;
	xspeed = 0;
	yspeed = 0;
	if (is_helddown(game->keymap, game->setting->controls.crouch))
		speed = PLAYER_CROUCH_SPEED * ((double)PLAYER_MOVE_BASE_FPS / game->frametime);
	else if (is_helddown(game->keymap, SDLK_LSHIFT))
		speed = PLAYER_RUN_SPEED * ((double)PLAYER_MOVE_BASE_FPS / game->frametime);
	else
		speed = PLAYER_MOVE_SPEED * ((double)PLAYER_MOVE_BASE_FPS / game->frametime);

	if (is_helddown(game->keymap, game->setting->controls.forward))
		draw |= move_forward(game->player, speed, &xspeed, &yspeed);
	if (is_helddown(game->keymap, game->setting->controls.backward))
		draw |= move_backward(game->player, speed, &xspeed, &yspeed);
	if (is_helddown(game->keymap, game->setting->controls.left))
		draw |= move_left(game->player, speed, &xspeed, &yspeed);
	if (is_helddown(game->keymap, game->setting->controls.right))
		draw |= move_right(game->player, speed, &xspeed, &yspeed);
	if (is_helddown(game->keymap, game->setting->controls.jump) || jump > 0)
		draw |= move_jump(game->player, &jump);
	if (draw == TRUE)
		player_col(game->player, game->map, xspeed, yspeed);
	return (draw);
}
