/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_enemy_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 16:06:50 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:49:39 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "rinfo.h"
#include "types.h"
#include "cmath.h"

static void	calc_second(t_game *game, t_enemy *en, SDL_Point *val, t_anim *an)
{
	static t_enemystate	pre = 0;
	t_uint64			time;

	if (en->state == ENEMY_ATTACK)
	{
		val->y = 2;
		return ;
	}
	time = get_gametime(&game->starttime) % MAX_ANIMATION_TIME;
	if (en->state == ENEMY_MOVING)
		val->y = time / (t_uint64)((float)MAX_ANIMATION_TIME * 0.25);
	else if (en->state == ENEMY_IDLE)
		val->y = time / (t_uint64)((float)MAX_ANIMATION_TIME * 0.5);
	else if (en->state == ENEMY_DEAD)
	{
		if (an->index.y != 1 || pre != ENEMY_DEAD)
			val->y = time / (t_uint64)((float)MAX_ANIMATION_TIME * 0.5);
		else
			val->y = 1;
	}
	pre = en->state;
}

void		get_enemy_index(t_game *game, void *anim)
{
	SDL_Point	val;
	t_anim		*an;
	float		angle;
	t_enemy		*enemy;

	an = anim;
	enemy = ((t_object*)an->data)->data;
	an = (t_anim*)anim;
	angle = wrap_float(an->angle - an->offset - 180, 0, 360);
	if (enemy->state > ENEMY_MOVING)
		val.x = 4;
	else if (angle >= 45 && angle < 135)
		val.x = 0;
	else if (angle >= 135 && angle < 225)
		val.x = 3;
	else if (angle >= 225 && angle < 315)
		val.x = 1;
	else
		val.x = 2;
	calc_second(game, enemy, &val, an);
	an->index = val;
}
