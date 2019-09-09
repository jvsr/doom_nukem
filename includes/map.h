/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:14:01 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 18:49:53 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <_types/_uint8_t.h>
#include <_types/_uint16_t.h>

#include "coord.h"

typedef struct	s_sprite
{

}				t_sprite;

typedef struct	s_wall
{
	
}				t_wall;

typedef struct	s_sector
{
	uint16_t	wall_index;
	uint16_t	wall_num;
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
** *	- uint16_t: Total number of sprites
** *	- t_sprite*: Array of all sprites
*/

typedef struct	s_map
{
	uint8_t		num_sector;
	t_sector	*all_sectors;
	uint16_t	num_wall;
	t_wall		*all_walls;
	uint16_t	num_sprite;
	t_sprite	*all_sprites;
}				t_map;

#endif
