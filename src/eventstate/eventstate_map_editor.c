/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_map_editor.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 11:06:09 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/13 14:09:06 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

#include "gui.h"
#include "onclick.h"
#include "game.h"
#include "cmath.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"
#include "keymap.h"
#include "map_editor.h"

static void	delete(t_game *game, SDL_Point mouse_pos,
				t_transform *map_editor_elem)
{
	t_editor_wall	*wall;
	t_editor_object	*object;

	wall = map_editor_check_hit_wall(map_editor_elem, game->editor_map,
		mouse_pos);
	if (wall != NULL)
		map_editor_del_wall(game->editor_map, wall);
	else
	{
		object = map_editor_check_hit_object(map_editor_elem, game->editor_map,
			mouse_pos);
		if (object == NULL)
			return ;
		map_editor_del_object(game->editor_map, object);
	}
	set_elem_redraw(map_editor_elem);
}

static void	toggle_wall(t_game *game, SDL_Point mouse_pos,
				t_transform *map_editor_elem)
{
	t_editor_wall	*wall;

	wall = map_editor_check_hit_wall(map_editor_elem, game->editor_map,
		mouse_pos);
	if (wall == NULL)
		return ;
	if (wall->is_hidden_door == TRUE)
	{
		wall->is_door = FALSE;
		wall->is_hidden_door = FALSE;
	}
	else if (wall->is_portal == FALSE && wall->is_door == FALSE)
		wall->is_portal = TRUE;
	else if (wall->is_window == FALSE && wall->is_door == FALSE)
		wall->is_window = TRUE;
	else if (wall->is_door == FALSE)
	{
		wall->is_door = TRUE;
		wall->is_portal = FALSE;
		wall->is_window = FALSE;
	}
	else if (wall->is_hidden_door == FALSE)
		wall->is_hidden_door = TRUE;
	set_elem_redraw(map_editor_elem);
}

void		mouse_move(t_game *game, SDL_Event event,
						t_transform *map_editor_elem)
{
	SDL_Point			mouse_pos;

	mouse_pos = (SDL_Point){event.button.x, event.button.y};
	if (event.button.button == SDL_BUTTON_LEFT &&
			is_helddown(game->keymap, SDLK_LCTRL) == TRUE)
		toggle_wall(game, mouse_pos, map_editor_elem);
	else if (event.button.button == SDL_BUTTON_LEFT)
		map_editor_add(game, mouse_pos, map_editor_elem);
	else if (event.button.button == SDL_BUTTON_RIGHT)
		delete(game, mouse_pos, map_editor_elem);
}

void		map_editor_eventstate(t_game *game, SDL_Event event)
{
	static t_bool		first = TRUE;
	t_transform			*map_editor_elem;

	map_editor_elem = get_gui_child(game->ui, "mapEditorView");
	if (event.type == SDL_MOUSEMOTION)
		set_elem_redraw(map_editor_elem);
	if (event.type == SDL_MOUSEBUTTONDOWN && first == FALSE)
	{
		if (event.button.x < 0 || event.button.x > map_editor_elem->abs_dim.x ||
			event.button.y < 0 || event.button.y > map_editor_elem->abs_dim.y)
			return ;
		mouse_move(game, event, map_editor_elem);
	}
	else
		first = get_gui_child(game->ui, "mapEditorConfirmationMenu")->show;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
	{
		map_editor_add_confirmation(game);
		first = TRUE;
	}
}
