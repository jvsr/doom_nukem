/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:16:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 17:28:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <_types/_uint8_t.h>
# include <_types/_uint32_t.h>

# include "coord.h"

typedef	struct	s_player
{
	t_uint16	hp;
	float		speed;
	t_bool		crouched;
	t_weapon	*cur_weapon;
	t_weapon	*all_weapon; //Keep list to allow adding mid game

	t_uint16	*fov;
	t_uint16	angle;
	t_pickup	**all_pickup;
	t_coord		pos;
	t_rect		view;
	t_uint8		detection_area;
}				t_player;

#endif
