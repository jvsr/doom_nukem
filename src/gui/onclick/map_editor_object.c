/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_object.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 15:07:03 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/13 15:12:56 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_num.h"

#include "gui.h"
#include "game.h"
#include "types.h"
#include "textures.h"
#include "eventstate.h"
#include "map_editor.h"
#include "error.h"

static void		set_object(t_game *game, t_obj object)
{
	t_transform	*elem;
	t_obj		*store;

	elem = get_gui_child(game->ui, "mapEditorObjectBlock");
	if (elem->user_data == NULL)
	{
		store = ft_memalloc(sizeof(t_obj));
		if (store == NULL)
			error_msg_errno("Failed to alloc Arguments");
	}
	else
		store = (t_obj*)elem->user_data;
	*store = object;
	set_elem_user_data(elem, store);
	if (object != O_INVALID)
		set_elem_image_texture(get_gui_child(game->ui,
			"mapEditorObjectTexture"),
			get_texture(game, get_tex_for_obj(object)));
	else
		set_elem_image_color(get_gui_child(game->ui, "mapEditorObjectTexture"),
			(SDL_Color){0, 0, 0, 0});
}

static t_obj	get_object(t_game *game)
{
	const t_transform	*elem = get_gui_child(game->ui, "mapEditorObjectBlock");

	if (elem->user_data == NULL)
		return ((t_obj)-1);
	return (*(t_obj*)elem->user_data);
}

void			map_editor_object_next(t_game *game, t_transform *elem)
{
	t_obj	current;

	(void)elem;
	current = get_object(game) + 1;
	current = ft_overflow(current, O_INVALID, O_COUNT);
	set_object(game, current);
}

void			map_editor_object_prv(t_game *game, t_transform *elem)
{
	t_obj	current;

	(void)elem;
	current = get_object(game) - 1;
	current = ft_overflow(current, O_INVALID, O_COUNT);
	set_object(game, current);
}

void			map_editor_object_select(t_game *game, t_transform *elem)
{
	t_transform	*map_editor_elem;

	(void)elem;
	map_editor_elem = get_gui_child(game->ui, "mapEditorView");
	map_editor_elem->gui_elem.map_editor->selected_object = get_object(game);
	set_elem_redraw(map_editor_elem);
}
