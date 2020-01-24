/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:47:55 by pholster       #+#    #+#                */
/*   Updated: 2020/01/21 21:33:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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
	uint64_t		cur;
	double			factor;
	float			speed;

	*jump = TRUE;
	if (momentum == UINT64_MAX)
		momentum = get_gametime(&game->starttime);
	cur = get_gametime(&game->starttime) - momentum;
	factor = (double)cur * ((double)PLAYER_MOVE_BASE_FPS / game->frametime) / CLOCKS_PER_MILLI;
	speed = PLAYER_INIT_DROP_SPEED - pow(factor * 3, 2.5);
	if (speed < 0)
		speed = 0;
	player->heightoffset += speed;
	if (cur > 500 || (game->map->sectors[player->cur_sector].has_ceiling && player->height + player->heightoffset >= game->map->sectors[player->cur_sector].ceil))
	{
		*jump = FALSE;
		momentum = UINT64_MAX;
		return (FALSE);
	}
	return (TRUE);
}

#include "libft/ft_printf.h"
static t_bool	move_down(t_game *game, t_player *player, t_bool *jump)
{
	static uint64_t	momentum = UINT64_MAX;
	uint64_t		cur;
	double			factor;

	if (momentum == UINT64_MAX)
		momentum = get_gametime(&game->starttime);
	cur = get_gametime(&game->starttime) - momentum;
	factor = (double)cur * ((double)PLAYER_MOVE_BASE_FPS / game->frametime) / CLOCKS_PER_MILLI;
	player->heightoffset -= pow(factor * 3, 2.2) + 1;
	if (player->heightoffset <= 0)
	{
		*jump = FALSE;
		player->heightoffset = 0;
		momentum = UINT64_MAX;
	}
	return (TRUE);
}

t_bool			player_move(t_game *game)
{
	t_bool			draw;
	float			speed;
	float			xspeed;
	float			yspeed;
	static t_bool	jump = FALSE;

	draw = FALSE;
	xspeed = 0;
	yspeed = 0;

	// float ratio = ((double)(get_gametime(&game->starttime) - game->frametime)) / CLOCKS_PER_SEC;
	// ft_printf("rat: %f\n", ratio);
	// ft_printf("rat: %ld\n", game->frametime);
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
	if (game->player->heightoffset > 0 && jump == FALSE)
		draw |= move_down(game, game->player, &jump);
	if ((is_helddown(game->keymap, game->setting->controls.jump) && game->player->heightoffset == 0 && jump == FALSE) || jump == TRUE)
		draw |= move_jump(game, game->player, &jump);
	if (draw == TRUE)
		player_col(game->player, game->map, xspeed, yspeed);
	// ft_printf("height: %5.2f, offset: %5.2f\n", game->player->height, game->player->heightoffset);
	return (draw);
}
