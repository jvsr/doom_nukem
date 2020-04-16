/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 12:56:47 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/14 21:34:30 by euan          ########   odam.nl         */
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
# define SAVE_LOCATION				"map/custom"
# define SAVE_NAME					"NewMap"
# define SHRINK_SIZE				3.0

typedef struct s_transform	t_transform;
typedef struct s_sector		t_sector;
typedef struct s_object		t_object;
typedef struct s_game		t_game;
typedef struct s_list		t_list;

typedef struct	s_editor_sector
{
	t_list		*walls;
	t_list		*objects;
	size_t		index;
	t_bool		is_invalid;
}				t_editor_sector;

typedef struct	s_editor_wall
{
	t_coord				corner_0;
	t_coord				corner_1;
	t_bool				is_portal;
	t_bool				is_window;
	t_bool				is_hidden_door;
	t_bool				is_door;
	t_editor_sector		*sectors[2];
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

typedef struct	s_angle_data
{
	float			ang;
	t_list			*lst_elem;
	t_editor_wall	*wall;
}				t_angle_data;

t_editor_map	*map_editor_new(void);
void			map_editor_del(t_editor_map **editor_map);

t_editor_wall	*map_editor_new_wall(t_editor_map *editor_map,
					t_coord corner_0, t_coord corner_1);
t_editor_object	*map_editor_new_object(t_editor_map *editor_map, t_obj type,
					t_coord pos);
t_bool			map_editor_add_wall(t_editor_map *editor_map,
					t_editor_wall *wall);
t_bool			map_editor_add_object(t_editor_map *editor_map,
					t_editor_object *object);
void			map_editor_add(t_game *game, SDL_Point mouse_pos,
					t_transform *map_editor_elem);

void			map_editor_snap_to_grid(t_transform *map_editor_elem,
					SDL_Point *point);
void			map_editor_remove_last_wall(t_editor_map *editor_map);
void			map_editor_del_wall(t_editor_map *editor_map,
					t_editor_wall *wall);
void			map_editor_del_object(t_editor_map *editor_map,
					t_editor_object *object);
t_bool			map_editor_hit_wall(t_editor_wall *wall, SDL_Point mouse);
t_bool			map_editor_wall_is_bigger(t_editor_wall *wall,
					t_editor_wall *other);
t_editor_wall	*map_editor_check_hit_wall(t_transform *map_editor_elem,
					t_editor_map *editor_map, SDL_Point mouse_pos);
t_editor_object	*map_editor_check_hit_object(t_transform *map_editor_elem,
					t_editor_map *editor_map, SDL_Point mouse_pos);
t_bool			map_editor_clean(t_editor_map *map);
void			convert_clean_doors(t_map *map);
void			map_objects(t_list *secs, t_list *objs);
t_list			*get_room(t_list *trail,
					t_list *walls, t_editor_wall *first, t_bool is_right);
t_list			*get_walls_at_wall(t_list *prv,
					t_editor_wall *wall, t_list *walls);
t_coord			*get_corner(t_editor_wall *wall, t_list *prv);
t_list			*get_connectors(t_list *walls);
t_list			*get_walls_at_point(t_coord *point,
					t_list *walls, t_editor_wall *cur);
t_bool			walls_equal(t_list **w0, t_list **w1);
void			clean_up_walls(t_editor_map *map);
t_list			*get_correct_sectors(t_editor_wall *con, t_list *walls);
void			remove_from_list(t_list **head, t_list *elm);
t_coord			get_wall_vector(t_editor_wall *main, t_editor_wall *sec);
t_map			*map_editor_convert(t_editor_map *m_edit);
t_editor_sector	*get_sector(t_list *walls, t_bool is_right);
void			free_ewall(void *wall, size_t size);
void			free_eobj(void *obj, size_t size);
void			free_esector(void *sec, size_t size);
t_editor_map	*map_editor_rev_convert(t_map *m);
t_bool			get_closest(float prev, float cur);
void			fill_wall(t_wall *cur_w, t_editor_wall *e_w);

#endif
