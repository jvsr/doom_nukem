/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:47:55 by pholster       #+#    #+#                */
/*   Updated: 2020/01/09 12:47:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <SDL2/SDL_keycode.h>

#include "libft/ft_str.h"

#include "cmath.h"
#include "player.h"
#include "keymap.h"

static t_bool	move_forward(t_player *player, float speed)
{
	float	xspeed;
	float	yspeed;

	xspeed = speed * cosf(player->angle * PI_R);
	yspeed = speed * sinf(player->angle * PI_R);
	player->pos.x += xspeed;
	player->pos.y += yspeed;
	return (TRUE);
}

static t_bool	move_backward(t_player *player, float speed)
{
	float	xspeed;
	float	yspeed;

	xspeed = -(speed * cos(player->angle * PI_R));
	yspeed = -(speed * sin(player->angle * PI_R));
	player->pos.x += xspeed;
	player->pos.y += yspeed;
	return (TRUE);
}

static t_bool	move_left(t_player *player, float speed)
{
	float	xspeed;
	float	yspeed;

	xspeed = speed * sin(player->angle * PI_R);
	yspeed = -(speed * cos(player->angle * PI_R));
	player->pos.x += xspeed;
	player->pos.y += yspeed;
	return (TRUE);
}

static t_bool	move_right(t_player *player, float speed)
{
	float	xspeed;
	float	yspeed;

	xspeed = -(speed * sin(player->angle * PI_R));
	yspeed = speed * cos(player->angle * PI_R);
	player->pos.x += xspeed;
	player->pos.y += yspeed;
	return (TRUE);
}

t_bool			player_move(t_player *player, t_hashmap *keymap)
{
	t_bool	draw;
	float	speed;

	draw = FALSE;
	if (is_helddown(keymap, SDLK_LSHIFT))
		speed = PLAYER_RUN_SPEED;
	else
		speed = PLAYER_MOVE_SPEED;
	if (is_helddown(keymap, SDLK_w))
		draw |= move_forward(player, speed);
	if (is_helddown(keymap, SDLK_s))
		draw |= move_backward(player, speed);
	if (is_helddown(keymap, SDLK_a))
		draw |= move_left(player, speed);
	if (is_helddown(keymap, SDLK_d))
		draw |= move_right(player, speed);
	return (draw);
}
