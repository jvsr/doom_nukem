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
#include "cmath.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"
#include "keymap.h"
#include "map_editor.h"

static void	manage_last_click(t_game *game, SDL_MouseButtonEvent button,
						t_map_editor *map_editor_gui_elem, t_bool *first_place)
{
	t_editor_wall	*wall;

	if (is_helddown(game->keymap, SDLK_LSHIFT) && game->editor_map->walls != NULL)
	{
		if (*first_place == TRUE)
		{
			wall = (t_editor_wall*)ft_lstlast(game->editor_map->walls)->content;
			map_editor_gui_elem->last_click.x = wall->corner_1.x;
			map_editor_gui_elem->last_click.y = wall->corner_1.y;
		}
		*first_place = FALSE;
	}
	else if (*first_place == TRUE)
	{
		map_editor_gui_elem->last_click.x = button.x;
		map_editor_gui_elem->last_click.y = button.y;
	}
}

static void	add_line(t_game *game, SDL_MouseButtonEvent button,
						t_transform *map_editor_elem)
{
	SDL_Point			current;
	t_map_editor		*map_editor_gui_elem;
	static	t_bool		first_place = TRUE;

	current.x = button.x;
	current.y = button.y;
	map_editor_gui_elem = map_editor_elem->gui_elem.map_editor;
	map_editor_snap_to_grid(map_editor_elem, &current);
	manage_last_click(game, button, map_editor_gui_elem, &first_place);
	if (first_place == FALSE && ft_memequ(&map_editor_gui_elem->last_click,
		&current, sizeof(SDL_Point)) == FALSE)
	{
		map_editor_new_wall(game->editor_map, (t_coord){
			map_editor_gui_elem->last_click.x, map_editor_gui_elem->last_click.y
		}, (t_coord){current.x, current.y});
		set_elem_redraw(map_editor_elem);
	}
	first_place = !first_place;
	map_editor_gui_elem->last_click = current;
	map_editor_gui_elem->show_last_click = !first_place;
}

static void	delete_line(t_game *game, SDL_MouseButtonEvent button,
				t_transform *map_editor_elem)
{
	t_editor_wall	*wall;

	wall = map_editor_check_hit(map_editor_elem, game->editor_map,
		(SDL_Point){button.x, button.y});
	if (wall == NULL)
		return ;
	map_editor_del_wall(game->editor_map, wall);
	set_elem_redraw(map_editor_elem);
}

static void	toggle_wall(t_game *game, SDL_MouseButtonEvent button,
				t_transform *map_editor_elem)
{
	t_editor_wall	*wall;

	wall = map_editor_check_hit(map_editor_elem, game->editor_map,
		(SDL_Point){button.x, button.y});
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
	} else if (wall->is_hidden_door == FALSE)
		wall->is_hidden_door = TRUE;
	set_elem_redraw(map_editor_elem);
}

void		map_editor_eventstate(t_game *game, SDL_Event event)
{
	static	t_bool		first = TRUE;
	t_transform			*map_editor_elem;

	map_editor_elem = get_gui_child(game->ui, "mapeditorview");
	if (event.button.x < 0 || event.button.x > map_editor_elem->abs_dim.x ||
		event.button.y < 0 || event.button.y > map_editor_elem->abs_dim.y)
		return ;
	if (event.type == SDL_MOUSEMOTION)
		set_elem_redraw(map_editor_elem);
	if (event.type == SDL_MOUSEBUTTONDOWN && first == FALSE)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
			add_line(game, event.button, map_editor_elem);
		else if (event.button.button == SDL_BUTTON_RIGHT)
			delete_line(game, event.button, map_editor_elem);
		else if (event.button.button == SDL_BUTTON_MIDDLE)
			toggle_wall(game, event.button, map_editor_elem);
	}
	else
		first = FALSE;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit(0);
}
