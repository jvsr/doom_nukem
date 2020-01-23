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

#include "coord.h"
#include "game.h"
#include "gui.h"
#include "map_editor.h"
#include "keymap.h"

static void	add_to_end(t_wall_line **head, t_wall_line *new)
{
	t_wall_line	*line;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	line = *head;
	while (line->next != NULL)
		line = line->next;
	line->next = new;
}

static void	add_line(t_game *game, SDL_Event event, t_transform *map_editor_elem)
{
	int					index;
	t_wall_line			*new;
	static	t_bool		first_place = TRUE;
	static	SDL_Point	points[2] = {{0, 0}, {0, 0}};

	if (is_helddown(game->keymap, SDLK_LSHIFT) && map_editor_elem->gui_elem.map_editor->line != NULL)
	{
		ft_memcpy(&points[0], &points[1], sizeof(SDL_Point));
		first_place = FALSE;
	}
	index = !first_place;
	points[index].x = event.button.x + map_editor_elem->gui_elem.map_editor->pos.x;
	points[index].y = event.button.y + map_editor_elem->gui_elem.map_editor->pos.y;
	if (first_place == FALSE)
	{
		new = (t_wall_line *)ft_memalloc(sizeof(t_wall_line));
		ft_memcpy(&new->line.start, &points[0], sizeof(SDL_Point));
		ft_memcpy(&new->line.end, &points[1], sizeof(SDL_Point));
		add_to_end(&map_editor_elem->gui_elem.map_editor->line, new);
		set_elem_redraw(map_editor_elem);
	}
	first_place = !first_place;
}

void		map_editor_eventstate(t_game *game, SDL_Event event)
{
	static	t_bool		first = TRUE;
	t_transform			*map_editor_elem;

	map_editor_elem = get_gui_child(game->ui, "mapeditorview");
	if (event.type == SDL_MOUSEBUTTONDOWN && first == FALSE)
		add_line(game, event, map_editor_elem);
	else
		first = FALSE;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z && is_helddown(game->keymap, SDLK_LCTRL))
	{
		t_wall_line	*line;
		t_wall_line	*prv;

		prv = NULL;
		line = map_editor_elem->gui_elem.map_editor->line;
		while (line != NULL && line->next != NULL)
		{
			prv = line;
			line = line->next;
		}
		if (prv != NULL)
			prv->next = NULL;
		else
			map_editor_elem->gui_elem.map_editor->line = NULL;
		ft_memdel((void **)&line);
		set_elem_redraw(map_editor_elem);
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		quit(0);
}
