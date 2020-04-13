/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_add.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 14:14:05 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/13 14:33:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

#include "gui.h"
#include "game.h"
#include "cmath.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"
#include "keymap.h"
#include "map_editor.h"

static void	manage_last_click(t_game *game, SDL_Point mouse_pos,
				t_map_editor *map_editor_gui_elem)
{
	t_editor_wall	*wall;

	if (is_helddown(game->keymap, SDLK_LSHIFT) &&
		game->editor_map->walls != NULL)
	{
		if (map_editor_gui_elem->show_last_click == FALSE)
		{
			wall = (t_editor_wall*)ft_lstlast(game->editor_map->walls)->content;
			map_editor_gui_elem->last_click.x = wall->corner_1.x;
			map_editor_gui_elem->last_click.y = wall->corner_1.y;
		}
		map_editor_gui_elem->show_last_click = TRUE;
	}
	else if (map_editor_gui_elem->show_last_click == FALSE)
	{
		map_editor_gui_elem->last_click.x = mouse_pos.x;
		map_editor_gui_elem->last_click.y = mouse_pos.y;
	}
}

static void	add_line(t_game *game, SDL_Point mouse_pos,
					t_transform *map_editor_elem)
{
	t_map_editor	*map_editor_gui_elem;

	map_editor_gui_elem = map_editor_elem->gui_elem.map_editor;
	map_editor_snap_to_grid(map_editor_elem, &mouse_pos);
	manage_last_click(game, mouse_pos, map_editor_gui_elem);
	if (map_editor_gui_elem->show_last_click == TRUE &&
		ft_memequ(&map_editor_gui_elem->last_click, &mouse_pos,
		sizeof(SDL_Point)) == FALSE)
	{
		map_editor_new_wall(game->editor_map, (t_coord){
			map_editor_gui_elem->last_click.x, map_editor_gui_elem->last_click.y
		}, (t_coord){mouse_pos.x, mouse_pos.y});
		set_elem_redraw(map_editor_elem);
	}
	map_editor_gui_elem->last_click = mouse_pos;
	map_editor_gui_elem->show_last_click =
		!map_editor_gui_elem->show_last_click;
}

static void	add_object(t_game *game, SDL_Point mouse_pos,
				t_transform *map_editor_elem)
{
	t_map_editor	*map_editor_gui_elem;

	map_editor_gui_elem = map_editor_elem->gui_elem.map_editor;
	mouse_pos.x += map_editor_gui_elem->pos.x;
	mouse_pos.y += map_editor_gui_elem->pos.y;
	map_editor_new_object(game->editor_map,
		map_editor_gui_elem->selected_object,
		(t_coord){mouse_pos.x, mouse_pos.y});
	map_editor_gui_elem->show_last_click = FALSE;
	set_elem_redraw(map_editor_elem);
}

void		map_editor_add(t_game *game, SDL_Point mouse_pos,
				t_transform *map_editor_elem)
{
	if (map_editor_elem->gui_elem.map_editor->selected_object == O_INVALID)
		add_line(game, mouse_pos, map_editor_elem);
	else
		add_object(game, mouse_pos, map_editor_elem);
}
