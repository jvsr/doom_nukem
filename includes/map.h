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

# define WALL_TEXTURE_SIDES	2
# define ENEMY_MOVE_ANGLES	6
# define ANIM_FRAMES	5

typedef	struct	s_player
{
	t_uint16	hp;
	float		speed;
	t_bool		crouched;
	t_weapon	*cur_weapon;
	t_weapon	**all_weapon;

	t_uint16	*fov;
	t_uint16	angle;
	t_pickup	**all_pickup;
	t_coord		pos;
	t_rect		view;
	t_uni8		detection_area;
}				t_player;

typedef struct	s_enemy
{
	t_uint16	hp
	t_uint8		fireate;
	t_uint8		damage;
	float		speed;
	float		range;
	enum		type;
	t_rect		view;

	SDL_Surface *death_texutre;
	enum 		death_sound;

	enum		anim_state;
	SDL_Surface *move_anim[ENEMY_MOVE_ANGLES][ANIM_FRAMES];
	SDL_Surface *attack_texure;
	t_sound		*shoot_sound;

	char			*name;
	t_coord			pos;
	t_bool			simulate;
	struct s_enemy	*next;
}				t_enemy;

typedef	struct	s_weapon
{
	t_uint64	last_shot;
	t_unit8		damage;
	t_uint16	max_ammo;
	t_uint16	cur_ammo;
	t_uint8		fireate;

	enum		anim_state;
	SDL_Surface	*texutre;
	SDL_Surface	*shoot_anim[ANIM_FRAMES];
	t_sound		*shoot_sound;
}				t_weapon;

typedef struct	s_interaction
{
	*f			con;
	*f			exec;
}				t_interaction;

typedef	struct	s_win_args
{
	t_uint16	win_mask;
	t_uint64	time;
	t_uint16	kill_count;
	t_sector	*end_sector;
	t_enemy		*boss;
}				t_win_args;

typedef struct	s_pickup
{
	t_coord			pos;
	t_interaction	*onpickup;
	SDL_Surface		*texture;
	SDL_Surface		*ui_icon;
}				t_pickup;

typedef struct	s_objects
{
	t_coord			pos;
	t_interaction	*interaction;
	SDL_Surface	*	texture;
}				t_object;

typedef	struct	s_decal
{
	t_interaction	*interaction;
	t_coord			pos;
	SDL_Surface		*texture;
}				t_decal;

typedef struct	s_wall
{
	t_interaction	*interaction;
	t_uint16		angle;
	t_coord			left_pos;
	SDL_Surface		*texture[WALL_TEXTURE_SIDES];
	t_unit8			height;
	t_bool			*colision;
	t_decal			*decals; //Keep list to allow adding mid game
}				t_wall;

typedef struct	s_sector
{
	*f			on_enter;
	*f			on_leave;
	t_uint16	num_pickup;
	t_pickup	**all_pickup;
	t_uint16	num_wall;
	t_uint16	*index_wall;
	t_uint16	num_object;
	t_uint16	*index_object;
	SDL_Surface	*floor_texture;
	t_uint8		z_floor; //ABS
	SDL_Surface	*ceiling_texture;
	t_uint8		z_ceiling; //ABS
}				t_sector;

typedef struct	s_level
{
	*f			init;
	t_win_args	*win_args;
	t_coord		player_start_pos;
	t_uint16	player_start_angle;
	t_enemy		**all_enemy; //Keep linked list to allow spawning while in level
	t_uint16	num_sector;
	t_sector	**all_sector;
	t_uint16	num_wall;
	t_wall		**all_wall;
	t_uint16	num_object;
	t_object	*all_object;
}				t_level;

#endif
