/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:47:55 by pholster       #+#    #+#                */
/*   Updated: 2020/02/11 18:21:28 by jvisser       ########   odam.nl         */
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

static t_bool	move_jump(t_game *game, t_player *player, t_bool *jump)
{
	static uint64_t	momentum = UINT64_MAX;
	static float	old_height;
	float			new_height;
	uint64_t		cur;

	*jump = TRUE;
	if (momentum == UINT64_MAX)
	{
		old_height = 0;
		momentum = get_gametime(&game->starttime);
	}
	cur = get_gametime(&game->starttime) - momentum;
	new_height = PLAYER_INIT_JUMP_HEIGHT - ( PLAYER_INIT_JUMP_HEIGHT * pow(1.0 - ((double)cur / PLAYER_JUMP_TIME), 2) );
	player->heightoffset += new_height - old_height;
	old_height = new_height;
	if (cur > PLAYER_JUMP_TIME || (game->map->sectors[player->cur_sector].has_ceiling && player->height + player->heightoffset >= game->map->sectors[player->cur_sector].ceil))
	{
		*jump = FALSE;
		momentum = UINT64_MAX;
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	move_down(t_game *game, t_player *player, t_bool *jump)
{
	static uint64_t	momentum = UINT64_MAX;
	static float	old_drop;
	float			new_drop;
	uint64_t		cur;
	
	if (momentum == UINT64_MAX)
	{
		old_drop = 0;
		momentum = get_gametime(&game->starttime);
	}
	cur = get_gametime(&game->starttime) - momentum;
	new_drop = PLAYER_INIT_JUMP_HEIGHT * pow((double)cur / PLAYER_JUMP_TIME, 2);
	player->heightoffset -= new_drop - old_drop;
	old_drop = new_drop;
	if (player->heightoffset <= 0)
	{
		*jump = FALSE;
		player->heightoffset = 0;
		momentum = UINT64_MAX;
	}
	return (TRUE);
}

static t_bool	fly_up(t_game *game, t_player *player, t_bool *jump)
{
	static float	height_to_go = 400;
	float			diff;

	diff = lerp(0, height_to_go, (float)game->lastframe / PLAYER_FLY_SPEED);
	if (player->height + player->heightoffset + diff < game->map->sectors[player->cur_sector].ceil)
		player->heightoffset += diff;
	*jump = TRUE;
	return (TRUE);
}

static t_bool	fly_down(t_game *game, t_player *player, t_bool *jump)
{
	static float	height_to_go = 400;
	float			diff;

	diff = lerp(0, height_to_go, (float)game->lastframe / PLAYER_FLY_SPEED);
	if (player->heightoffset - diff < 0)
		player->heightoffset = 0;
	else if (player->height + player->heightoffset - diff > game->map->sectors[player->cur_sector].floor)
		player->heightoffset -= diff;
	*jump = FALSE;
	return (TRUE);
}

t_bool			player_move(t_game *game)
{
	t_bool			draw;
	float			speed;
	float			xspeed;
	float			yspeed;
	static t_bool	jump = FALSE;
	// static uint64_t	last_frame = 0;
	double		frametime;
	
	draw = FALSE;
	xspeed = 0;
	yspeed = 0;

	frametime = (double)game->lastframe;
	// float ratio = ((double)(get_gametime(&game->starttime) - game->frametime)) / CLOCKS_PER_SEC;
	// ft_printf("rat: %f\n", ratio);
	// ft_printf("rat: %ld\n", game->frametime);
	if (game->player->player_height == PLAYER_CROUCH)
		speed = PLAYER_CROUCH_SPEED ;
	else if (is_helddown(game->keymap, SDLK_LSHIFT))
		speed = PLAYER_RUN_SPEED ;
	else
		speed = PLAYER_MOVE_SPEED ;

	if (is_helddown(game->keymap, game->setting->controls.forward))
		draw |= move_forward(game->player, speed, &xspeed, &yspeed);
	if (is_helddown(game->keymap, game->setting->controls.backward))
		draw |= move_backward(game->player, speed, &xspeed, &yspeed);
	if (is_helddown(game->keymap, game->setting->controls.left))
		draw |= move_left(game->player, speed, &xspeed, &yspeed);
	if (is_helddown(game->keymap, game->setting->controls.right))
		draw |= move_right(game->player, speed, &xspeed, &yspeed);

	if (!game->player->is_flying)
	{
		if (game->player->heightoffset > 0 && jump == FALSE)
			draw |= move_down(game, game->player, &jump);
		if ((is_helddown(game->keymap, game->setting->controls.jump) && game->player->heightoffset == 0 && jump == FALSE) || jump == TRUE)
			draw |= move_jump(game, game->player, &jump);
	}
	else
	{
		if (is_helddown(game->keymap, game->setting->controls.jump))
			draw |= fly_up(game, game->player, &jump);
		else if (is_helddown(game->keymap, game->setting->controls.crouch))
			draw |= fly_down(game, game->player, &jump);
	}
	xspeed = lerp_max(0, xspeed, frametime / BASE_FRAME_TIME, INFINITY);
	yspeed = lerp_max(0, yspeed, frametime / BASE_FRAME_TIME, INFINITY);
	if (draw == TRUE)
		player_col(game, xspeed, yspeed);
	// ft_printf("height: %5.2f, offset: %5.2f\n", game->player->height, game->player->heightoffset);
	return (draw);
}
