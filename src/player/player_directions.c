/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_directions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:39:36 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:21 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cmath.h"
#include "player.h"

t_bool	move_forward(t_player *player, float speed,
								float *xspeed, float *yspeed)
{
	*xspeed += speed * cosf(player->angle * PI_R);
	*yspeed += speed * sinf(player->angle * PI_R);
	return (TRUE);
}

t_bool	move_backward(t_player *player, float speed,
								float *xspeed, float *yspeed)
{
	*xspeed += -(speed * cos(player->angle * PI_R));
	*yspeed += -(speed * sin(player->angle * PI_R));
	return (TRUE);
}

t_bool	move_left(t_player *player, float speed,
								float *xspeed, float *yspeed)
{
	*xspeed += speed * sin(player->angle * PI_R);
	*yspeed += -(speed * cos(player->angle * PI_R));
	return (TRUE);
}

t_bool	move_right(t_player *player, float speed,
								float *xspeed, float *yspeed)
{
	*xspeed += -(speed * sin(player->angle * PI_R));
	*yspeed += speed * cos(player->angle * PI_R);
	return (TRUE);
}
