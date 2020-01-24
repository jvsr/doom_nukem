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

# define EDITOR_BACKGROUND_COLOR "333333"
# define EDITOR_LINE_COLOR	"FFFFFF"
# define EDITOR_GRID_COLOR	"555555"
# define EDITOR_GRID_STEP	20
# define EDITOR_MOVE_SPEED	5
# define EDITOR_GRID_START_OFFSET 1

typedef	struct s_wall		t_wall;
typedef	struct s_transform	t_transform;

void	map_editor_snap_to_grid(t_transform *map_editor_elem, SDL_Point *point);
void	map_editor_remove_last_wall(t_transform *map_editor_elem);
void	map_editor_add_wall(t_transform *map_editor_elem, t_wall *wall);

#endif
