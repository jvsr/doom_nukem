/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_main_menu.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:28:08 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:46:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_thread.h>

#include "libft/ft_bool.h"

#include "gui.h"
#include "game.h"
#include "gui_config.h"

static t_transform	*create_gui(t_game *game, char const *name)
{
	return (analyze_gui_config(game->ui, name, game->exec_path));
}

void				*init_main_menu(t_game *game)
{
	t_transform	*main_menu;
	t_transform	*options_menu;

	main_menu = create_gui(game, "main_menu");
	options_menu = create_gui(game, "options_menu");
	add_elem_child(options_menu, create_gui(game, "controls_menu"));
	add_elem_child(main_menu, options_menu);
	add_elem_child(main_menu, create_gui(game, "select_level"));
	add_gui_child(game->ui, main_menu);
	add_gui_child(game->ui, create_gui(game, "map_editor_select"));
	add_gui_child(game->ui, create_gui(game, "hud"));
	add_gui_child(game->ui, create_gui(game, "hud_died"));
	add_gui_child(game->ui, create_gui(game, "hud_options"));
	add_gui_child(game->ui, create_gui(game, "map_editor"));
	add_gui_child(game->ui, create_gui(game, "hud_win"));
	set_elem_show_clickable(get_gui_child(game->ui, "mapEditor"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mapEditorSelect"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "hud"), FALSE);
	return (NULL);
}
