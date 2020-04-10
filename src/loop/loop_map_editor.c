/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_map_editor.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:37:51 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/01/14 15:55:25 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "map_editor.h"
#include "keymap.h"

static t_bool	move(t_transform *map_editor_elem, t_hashmap *keymap)
{
	t_bool				draw;

	draw = FALSE;
	if (is_helddown(keymap, SDLK_LEFT))
	{
		map_editor_elem->gui_elem.map_editor->pos.x -= EDITOR_MOVE_SPEED;
		draw |= TRUE;
	}
	if (is_helddown(keymap, SDLK_RIGHT))
	{
		map_editor_elem->gui_elem.map_editor->pos.x += EDITOR_MOVE_SPEED;
		draw |= TRUE;
	}
	if (is_helddown(keymap, SDLK_UP))
	{
		map_editor_elem->gui_elem.map_editor->pos.y -= EDITOR_MOVE_SPEED;
		draw |= TRUE;
	}
	if (is_helddown(keymap, SDLK_DOWN))
	{
		map_editor_elem->gui_elem.map_editor->pos.y += EDITOR_MOVE_SPEED;
		draw |= TRUE;
	}
	return (draw);
}

void			loop_map_editor(t_game *game)
{
	t_bool				draw;
	t_transform			*map_editor_elem;

	draw = FALSE;
	map_editor_elem = get_gui_child(game->ui, "mapeditorview");
	draw |= move(map_editor_elem, game->keymap);
	if (draw)
		set_elem_redraw(map_editor_elem);
}
