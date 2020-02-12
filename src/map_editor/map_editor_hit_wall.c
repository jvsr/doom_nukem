/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_hit_wall.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 14:14:19 by pholster       #+#    #+#                */
/*   Updated: 2020/02/12 14:14:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "cmath.h"
#include "rinfo.h"
#include "map_editor.h"

t_bool	map_editor_hit_wall(t_wall *wall, SDL_Point mouse)
{
	t_coord	const	mouse_pos = {mouse.x, mouse.y};

	return (circle_collision(wall->corner_0, wall->corner_1, mouse_pos,
		EDITOR_MOUSE_COLISION_SIZE));
}
