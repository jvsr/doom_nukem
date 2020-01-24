/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_snap_to_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 11:44:58 by pholster       #+#    #+#                */
/*   Updated: 2020/01/24 11:44:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "map_editor.h"

void	map_editor_snap_to_grid(t_transform *map_editor_elem, SDL_Point *point)
{
	int		offset_x;
	int		offset_y;

	point->x += map_editor_elem->gui_elem.map_editor->pos.x;
	point->y += map_editor_elem->gui_elem.map_editor->pos.y;
	offset_x = (point->x - EDITOR_GRID_START_OFFSET) % EDITOR_GRID_STEP;
	offset_y = (point->y - EDITOR_GRID_START_OFFSET) % EDITOR_GRID_STEP;
	if (offset_x > (int)round((float)EDITOR_GRID_STEP / 2))
		offset_x -= EDITOR_GRID_STEP;
	if (offset_y > (int)round((float)EDITOR_GRID_STEP / 2))
		offset_y -= EDITOR_GRID_STEP;
	point->x -= offset_x;
	point->y -= offset_y;
}
