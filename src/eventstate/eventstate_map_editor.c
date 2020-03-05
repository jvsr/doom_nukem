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

static void	manage_last_click(t_game *game, SDL_Event event,
						t_map_editor *map_editor_gui_elem, t_bool *first_place)
{
	t_wall	*wall;

	if (is_helddown(game->keymap, SDLK_LSHIFT) && game->editor_map->walls != NULL)
	{
		if (*first_place == TRUE)
		{
			wall = (t_wall*)ft_lstlast(game->editor_map->walls)->content;
			map_editor_gui_elem->last_click.x = wall->corner_1.x;
			map_editor_gui_elem->last_click.y = wall->corner_1.y;
		}
		*first_place = FALSE;
	}
	else if (*first_place == TRUE)
	{
		map_editor_gui_elem->last_click.x = event.button.x;
		map_editor_gui_elem->last_click.y = event.button.y;
	}
}

static void	add_line(t_game *game, SDL_Event event,
						t_transform *map_editor_elem)
{
	t_wall				*new;
	SDL_Point			current;
	t_map_editor		*map_editor_gui_elem;
	static	t_bool		first_place = TRUE;

	current.x = event.button.x;
	current.y = event.button.y;
	map_editor_gui_elem = map_editor_elem->gui_elem.map_editor;
	map_editor_snap_to_grid(map_editor_elem, &current);
	manage_last_click(game, event, map_editor_gui_elem, &first_place);
	if (first_place == FALSE && ft_memequ(&map_editor_gui_elem->last_click,
		&current, sizeof(SDL_Point)) == FALSE)
	{
		new = (t_wall*)ft_memalloc(sizeof(t_wall));
		if (new == NULL)
			error_msg_errno("Failed to alloc new mapeditor wall");
		new->corner_0.x = map_editor_gui_elem->last_click.x;
		new->corner_0.y = map_editor_gui_elem->last_click.y;
		new->corner_1.x = current.x;
		new->corner_1.y = current.y;
		map_editor_add_wall(game->editor_map, new);
		set_elem_redraw(map_editor_elem);
	}
	first_place = !first_place;
	map_editor_gui_elem->last_click = current;
	map_editor_gui_elem->show_last_click = !first_place;
}

static void	delete_line(t_game *game, SDL_Event event, t_transform *map_editor_elem)
{
	t_list		*lst;
	t_wall		*wall;
	t_wall		*found;
	t_coord		mouse_pos;

	found = NULL;
	mouse_pos.x = event.button.x + map_editor_elem->gui_elem.map_editor->pos.x;
	mouse_pos.y = event.button.y + map_editor_elem->gui_elem.map_editor->pos.y;
	lst = game->editor_map->walls;
	while (lst != NULL)
	{
		wall = (t_wall *)lst->content;
		if (circle_collision(&(t_bicoord){wall->corner_0, wall->corner_1}, 
			&mouse_pos, EDITOR_MOUSE_COLISION_SIZE))
			found = wall;
		lst = lst->next;
	}
	if (found == NULL)
		return ;
	map_editor_delete_wall(game->editor_map, found);
	set_elem_redraw(map_editor_elem);
}

void		map_editor_eventstate(t_game *game, SDL_Event event)
{
	static	t_bool		first = TRUE;
	t_transform			*map_editor_elem;

	map_editor_elem = get_gui_child(game->ui, "mapeditorview");
	if (event.type == SDL_MOUSEMOTION)
		set_elem_redraw(map_editor_elem);
	if (event.type == SDL_MOUSEBUTTONDOWN && first == FALSE)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
			add_line(game, event, map_editor_elem);
		else if (event.button.button == SDL_BUTTON_RIGHT)
			delete_line(game, event, map_editor_elem);
	}
	else
		first = FALSE;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit(0);
}
