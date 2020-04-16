/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_object_angle_on_screen.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:14:44 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/13 12:09:55 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "player.h"
#include "rinfo.h"
#include "coord.h"
#include "cmath.h"

float	get_object_angle_on_screen(t_object *object,
										t_player *player, t_coord *range)
{
	float	obj_ang;
	t_coord	vec;

	vec = (t_coord){object->pos.x - player->pos.x,
			object->pos.y - player->pos.y};
	obj_ang = wrap_angle(atan2(vec.y, vec.x) * PI_D);
	if (is_between_fov(obj_ang, range->x, range->y))
		return (obj_ang);
	return (-1);
}
