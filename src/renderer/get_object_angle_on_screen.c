/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_object_angle_on_screen.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:14:44 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/24 15:14:44 by ehollidg      ########   odam.nl         */
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
	float obj_ang;

	obj_ang = (get_angle_between_points(&object->pos, &player->pos) * PI_D) +
				180;
	if (is_between_fov(obj_ang, range->x, range->y))
		return (obj_ang);
	return (-1);
}
