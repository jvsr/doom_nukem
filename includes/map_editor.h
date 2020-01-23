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

# include "shape.h"
# include <SDL2/SDL_surface.h>

# define EDITOR_BACKGROUND_COLOR "333333"
# define EDITOR_LINE_COLOR	"FFFFFF"
# define EDITOR_GRID_COLOR	"555555"
# define EDITOR_GRID_STEP	20
# define EDITOR_MOVE_SPEED	5

typedef struct s_wall_line	t_wall_line;

struct		s_wall_line
{
	t_line		line;
	t_wall_line	*next;
};

#endif
