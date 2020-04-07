/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_check_hit_wall.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/26 13:30:37 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/26 13:30:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"

#include "gui.h"
#include "cmath.h"
#include "map_editor.h"

t_editor_wall	*map_editor_check_hit_wall(t_transform *map_editor_elem,
					t_editor_map *editor_map, SDL_Point mouse_pos)
{
	t_list			*lst;
	t_editor_wall	*wall;
	t_coord			snap_pos;

	snap_pos.x = mouse_pos.x + map_editor_elem->gui_elem.map_editor->pos.x;
	snap_pos.y = mouse_pos.y + map_editor_elem->gui_elem.map_editor->pos.y;
	lst = editor_map->walls;
	while (lst != NULL)
	{
		wall = (t_editor_wall*)lst->content;
		if (circle_collision(&(t_bicoord){wall->corner_0, wall->corner_1},
			&snap_pos, EDITOR_MOUSE_COLISION_SIZE))
			return (wall);
		lst = lst->next;
	}
	return (NULL);
}
