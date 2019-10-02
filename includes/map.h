/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:14:01 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 12:00:02 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "types.h"
# include "coord.h"

# define WALL_TEXTURE_SIDES	6
// # define ANIM_FRAMES	40

typedef	struct	s_player
{
	detection_area
}				t_player;

typedef struct	s_enemy
{
	hp
	speed
	range
	type
	detection_area

	anim_state;
	// SDL_Surface move_anim[ANIM_FRAMES];
	// SDL_Surface shoot_anim[ANIM_FRAMES];

	enum sound;
	char			*name;
	t_coord			pos;
	t_bool			simulate;
	struct s_enemy	*next;
}				t_enemy;

typedef struct	s_objects
{

}				t_object;

typedef struct	s_wall
{
	t_uint16	angle;
	t_coord		left_pos;
	SDL_Surface	texture[WALL_TEXTURE_SIDES];
	t_unit8		height;
}				t_wall;

typedef struct	s_sector
{
	t_uint8		height;
	t_object	*objects;
	uint16_t	*wall_indexs;
}				t_sector;

/*
** * File Format:
** *	- t_vec: Player starting pos
** *	- uint32_t: Player starting angle
** *	- uint8_t: Player starting sector
** *	- uint8_t: Total number of sectors
** *	- t_sector*: Array of all sectors
** *	- uint16_t: Total number of walls
** *	- t_wall*: Array of all walls
** *	- uint16_t: Total number of objects
** *	- t_object*: Array of all objects
*/

typedef struct	s_level
{
	t_coord		player_start_pos;
	t_uint16	player_start_angle;
	t_enemy		*enemys; //Keep linked list to allow spawning while in level
	t_uint8		num_sector;
	t_sector	*all_sectors;
	// uint16_t	num_wall;
	// t_wall		*all_walls;
	// uint16_t	num_object;
	// t_object	*all_objects;
}				t_level;

#endif
