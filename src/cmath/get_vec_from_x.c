/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_vec_from_x.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 16:57:49 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:57 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "setting.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "cmath.h"
#include "game.h"

t_coord		get_vec_from_x(t_rinfo *rin, int x)
{
	float	val;
	t_coord	ret;

	val = (float)x / (float)rin->dst->w;
	val *= rin->game->setting->fov;
	val = wrap_angle(rin->game->player->angle - rin->hfov2 + val);
	get_vector_from_angle(val, &ret);
	return (ret);
}
