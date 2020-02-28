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

# include "shape.h"
# include "types.h"

# define EDITOR_MOUSE_COLISION_SIZE	3
# define EDITOR_PREVIEW_CIRCLE_SIZE	6
# define EDITOR_WALL_CORNER_SIZE	6
# define EDITOR_PREVIEW_PLACE_COLOR	"11AAAA"
# define EDITOR_BACKGROUND_COLOR 	"333333"
# define EDITOR_WALL_COLOR		 	"FFFFFF"
# define EDITOR_PORTAL_COLOR		"FF6666"
# define EDITOR_GRID_COLOR			"555555"
# define EDITOR_GRID_STEP			20
# define EDITOR_MOVE_SPEED			5
# define EDITOR_GRID_START_OFFSET	1

typedef struct s_transform	t_transform;
typedef struct s_sector		t_sector;
typedef struct s_object		t_object;
typedef struct s_wall		t_wall;
typedef struct s_game		t_game;
typedef struct s_list		t_list;

typedef struct	s_editor_sector
{
	float		floor;
	float		ceil;
	t_list		*walls;
	t_list		*objects;
	t_bool		has_ceiling;
	void		(*f_enter)(t_game *game, t_sector *cur_sector);
	void		(*f_exit)(t_game *game, t_sector *cur_sector);
	float		light_value;
}				t_editor_sector;

typedef struct	s_editor_map
{
	t_list		*walls;
	t_list		*objects;
	t_list		*sectors;
	t_bool		has_skybox;
	t_texture	skybox;
}				t_editor_map;

t_editor_map	*map_editor_new(void);
void			map_editor_delete(t_editor_map **editor_map);

void			map_editor_snap_to_grid(t_transform *map_editor_elem,
					SDL_Point *point);
void			map_editor_remove_last_wall(t_editor_map *editor_map);
void			map_editor_add_wall(t_editor_map *editor_map, t_wall *wall);
void			map_editor_delete_wall(t_editor_map *editor_map, t_wall *wall);
t_bool			map_editor_hit_wall(t_wall *wall, SDL_Point mouse);

t_editor_sector	*map_editor_find_wall_sector(t_editor_map *editor_map,
					t_wall *wall);
t_editor_sector	*map_editor_find_object_sector(t_editor_map *editor_map,
					t_object *object);

#endif
