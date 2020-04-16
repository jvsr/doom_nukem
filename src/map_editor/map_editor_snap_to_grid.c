/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_snap_to_grid.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 11:44:58 by pholster      #+#    #+#                 */
/*   Updated: 2020/01/24 11:44:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "map_editor.h"

static int	calc_offset(int axis)
{
	int		offset;

	offset = (axis - EDITOR_GRID_START_OFFSET) % EDITOR_GRID_STEP;
	if (abs(offset) > (int)round((float)EDITOR_GRID_STEP / 2))
	{
		if (offset < 0)
			offset += EDITOR_GRID_STEP;
		else
			offset -= EDITOR_GRID_STEP;
	}
	return (offset);
}

void		map_editor_snap_to_grid(t_transform *map_editor_elem,
				SDL_Point *point)
{
	point->x += map_editor_elem->gui_elem.map_editor->pos.x;
	point->y += map_editor_elem->gui_elem.map_editor->pos.y;
	point->x -= calc_offset(point->x);
	point->y -= calc_offset(point->y);
}
