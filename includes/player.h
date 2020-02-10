/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:16:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/10 15:09:56 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "types.h"
# include "coord.h"

# define PLAYER_HEIGHT 9.0
# define PLAYER_CROUCH 5.0
# define PLAYER_JUMP 20.0
# define PLAYER_JUMP_FRAMES 20
# define PLAYER_UPDOWN_MIN -0.45
# define PLAYER_UPDOWN_MAX 0.60
# define PLAYER_MOVE_SPEED 0.5
# define PLAYER_RUN_SPEED 0.7
# define PLAYER_CLIMB 5.0
# define PLAYER_CROUCH_SPEED 0.2
# define PLAYER_H_SENSE 0.12
# define PLAYER_V_SENSE 0.002
# define PLAYER_MOVE_BASE_FPS 40
# define PLAYER_INIT_DROP_SPEED 2.5
# define PLAYER_MAX_HEALTH 50

typedef struct s_game		t_game;
typedef struct s_hashmap	t_hashmap;
typedef struct s_map		t_map;

typedef struct	s_mag
{
	double cos;
	double sin;
}				t_mag;

typedef	struct	s_player
{
	/*
	float		speed;
	t_weapon	*cur_weapon;
	t_weapon	*all_weapon; //Keep list to allow adding mid game

	t_pickup	**all_pickup;
	t_rect		vienor
	t_uint8		detection_area;
	*/
	t_uint32	health;
	t_uint16	*fov;
	float		angle;
	t_mag		mag;
	t_coord		forward;
	t_coord		pos;
	t_uint32	cur_sector;
	float		height;
	float		player_height;
	float		heightoffset;
	float		updown;
	int			screen_updown;
}				t_player;

t_bool			player_move(t_game *game);
t_bool			player_col(t_game *game, float xspeed, float yspeed);

#endif
