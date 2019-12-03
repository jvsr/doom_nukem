/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:16:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/28 14:54:17 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <_types/_uint8_t.h>
# include <_types/_uint32_t.h>

# include "types.h"
# include "coord.h"

# define PLAYER_HEIGHT 2.0

typedef struct	s_mag
{
	float start;
	float end;
}				t_mag;

typedef	struct	s_player
{
	/*t_uint16	hp;
	float		speed;
	t_bool		crouched;
	t_weapon	*cur_weapon;
	t_weapon	*all_weapon; //Keep list to allow adding mid game

	t_pickup	**all_pickup;
	t_rect		view;
	t_uint8		detection_area;*/
	t_uint16	*fov;
	float		angle;
	t_mag		mag;
	t_coord		forward;
	t_vec		pos;
	t_uint32	cur_sector;
	float		height;
}				t_player;

#endif
