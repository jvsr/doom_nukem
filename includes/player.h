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

# define PLAYER_HEIGHT 6.0
# define PLAYER_CROUCH 3.0
# define PLAYER_JUMP 9.0
# define PLAYER_UPDOWN_MIN -0.15
# define PLAYER_UPDOWN_MAX 0.25
# define PLAYER_MOVE_SPEED 0.5
# define PLAYER_RUN_SPEED 1
# define PLAYER_V_SENSE 0.001

typedef struct s_hashmap	t_hashmap;
typedef struct s_map		t_map;

typedef struct	s_mag
{
	float cos;
	float sin;
}				t_mag;

typedef	struct	s_player
{
	/*t_uint16	hp;
	float		speed;
	t_bool		crouched;
	t_weapon	*cur_weapon;
	t_weapon	*all_weapon; //Keep list to allow adding mid game

	t_pickup	**all_pickup;
	t_rect		vienor
	t_uint8		detection_area;*/
	t_uint16	*fov;
	float		angle;
	t_mag		mag;
	t_coord		forward;
	t_coord		pos;
	t_uint32	cur_sector;
	float		height;
	float		heightoffset;
	float		updown;
}				t_player;

t_bool			player_move(t_player *player, t_hashmap *keymap, t_map *map);
t_bool			player_col(t_player *player,
									t_map *map, float xspeed, float yspeed);

#endif
