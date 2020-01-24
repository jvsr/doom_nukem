/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_map_editor.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 11:06:09 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/14 12:22:18 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

#include "gui.h"
#include "game.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"
#include "keymap.h"
#include "map_editor.h"

static void	add_line(t_game *game, SDL_Event event,
						t_transform *map_editor_elem)
{
	int					index;
	t_wall				*new;
	t_wall				*wall;
	static	t_bool		first_place = TRUE;
	static	SDL_Point	points[2] = {{0, 0}, {0, 0}};

	if (is_helddown(game->keymap, SDLK_LSHIFT) && map_editor_elem->gui_elem.map_editor->wall != NULL)
	{
		wall = (t_wall*)ft_lstlast(map_editor_elem->gui_elem.map_editor->wall)->content;
		points[0].x = wall->corner_1.x;
		points[0].y = wall->corner_1.y;
		first_place = FALSE;
	}
	index = !first_place;
	points[index].x = event.button.x;
	points[index].y = event.button.y;
	map_editor_snap_to_grid(map_editor_elem, &points[index]);
	if (first_place == FALSE)
	{
		new = (t_wall*)ft_memalloc(sizeof(t_wall));
		if (new == NULL)
			error_msg_errno("Failed to alloc new mapeditor wall");
		new->corner_0.x = points[0].x;
		new->corner_0.y = points[0].y;
		new->corner_1.x = points[1].x;
		new->corner_1.y = points[1].y;
		map_editor_add_wall(map_editor_elem, new);
	}
	first_place = !first_place;
}

void		map_editor_eventstate(t_game *game, SDL_Event event)
{
	static	t_bool		first = TRUE;
	t_transform			*map_editor_elem;

	map_editor_elem = get_gui_child(game->ui, "mapeditorview");
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && first == FALSE)
		add_line(game, event, map_editor_elem);
	else
		first = FALSE;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z && is_helddown(game->keymap, SDLK_LCTRL))
		map_editor_remove_last_wall(map_editor_elem);
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit(0);
}
