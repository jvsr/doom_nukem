/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 12:56:47 by pholster       #+#    #+#                */
/*   Updated: 2020/01/17 12:56:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# include <SDL2/SDL_surface.h>

# include "rinfo.h"
# include "coord.h"
# include "shape.h"
# include "types.h"

# define EDITOR_MOUSE_COLISION_SIZE	5
# define EDITOR_PREVIEW_CIRCLE_SIZE	6
# define EDITOR_WALL_CORNER_SIZE	6
# define EDITOR_PREVIEW_PLACE_COLOR	"11AAAA"
# define EDITOR_BACKGROUND_COLOR 	"333333"
# define EDITOR_HIDDEN_DOOR_COLOR	"E5AC3A"
# define EDITOR_DOOR_COLOR			"3F923F"
# define EDITOR_WINDOW_COLOR		"1982D2"
# define EDITOR_PORTAL_COLOR		"FF6666"
# define EDITOR_WALL_COLOR		 	"FFFFFF"
# define EDITOR_GRID_COLOR			"555555"
# define EDITOR_GRID_STEP			20
# define EDITOR_MOVE_SPEED			5
# define EDITOR_GRID_START_OFFSET	1

typedef struct s_transform	t_transform;
typedef struct s_sector		t_sector;
typedef struct s_object		t_object;
typedef struct s_game		t_game;
typedef struct s_list		t_list;

typedef struct	s_editor_sector
{
	float		floor;
	float		ceil;
	t_texture	floor_tex;
	t_texture	ceil_tex;
	t_bool		has_ceiling;
	float		light_value;
	t_bool		has_slope;
	float		angle;
}				t_editor_sector;

typedef struct	s_editor_wall
{
	t_coord				corner_0;
	t_coord				corner_1;
	t_bool				is_portal;
	t_bool				is_window;
	t_bool				is_hidden_door;
	t_bool				is_door;
	t_anim				left_texture;
	t_editor_sector		*left_sector;
	t_anim				right_texture;
	t_editor_sector		*right_sector;
	t_anim				win_tex;
	t_coord				perc;
	t_list				*decals;
}				t_editor_wall;

typedef struct	s_editor_object
{
	t_obj			type;
	t_coord			pos;
	t_editor_sector	*sector;
}				t_editor_object;

typedef struct	s_editor_map
{
	t_list		*walls;
	t_list		*objects;
	t_list		*sectors;
	t_bool		has_skybox;
	t_texture	skybox;
}				t_editor_map;

t_editor_map	*map_editor_new(void);
void			map_editor_del(t_editor_map **editor_map);

t_editor_wall	*map_editor_new_wall(t_editor_map *editor_map, t_coord corner_0,
					t_coord corner_1);
void			map_editor_add_wall(t_editor_map *editor_map,
					t_editor_wall *wall);

void			map_editor_snap_to_grid(t_transform *map_editor_elem,
					SDL_Point *point);
void			map_editor_remove_last_wall(t_editor_map *editor_map);
void			map_editor_del_wall(t_editor_map *editor_map,
					t_editor_wall *wall);
t_bool			map_editor_hit_wall(t_editor_wall *wall, SDL_Point mouse);
t_bool			map_editor_wall_is_bigger(t_editor_wall *wall,
					t_editor_wall *other);
t_editor_wall	*map_editor_check_hit(t_transform *map_editor_elem,
					t_editor_map *editor_map, SDL_Point mouse_pos);

#endif
