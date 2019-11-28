/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_main_menu.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:28:08 by jvisser        #+#    #+#                */
<<<<<<< HEAD:src/main/init_main_menu.c
/*   Updated: 2019/11/14 11:34:24 by jvisser       ########   odam.nl         */
=======
/*   Updated: 2019/11/13 11:20:49 by jvisser       ########   odam.nl         */
>>>>>>> 902071b0a5c1d877af5268d2c75fc4a7a48c2f63:src/init/init_main_menu.c
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_thread.h>

#include "libft/ft_bool.h"

#include "gui.h"
#include "game.h"
#include "gui_config.h"

void	init_main_menu(t_game *game)
{
	t_transform	*main_menu;
	t_transform	*map_editor_select;
	t_transform	*options_menu;
	t_transform	*select_level;
	t_transform	*controls_menu;

	main_menu = analyze_gui_config(game->ui, "main_menu");
	map_editor_select = analyze_gui_config(game->ui, "map_editor_select");
	options_menu = analyze_gui_config(game->ui, "options_menu");
	select_level = analyze_gui_config(game->ui, "select_level");
	controls_menu = analyze_gui_config(game->ui, "controls_menu");
	add_elem_child(options_menu, controls_menu);
	add_elem_child(main_menu, options_menu);
	add_elem_child(main_menu, select_level);
	add_gui_child(game->ui, main_menu);
<<<<<<< HEAD:src/main/init_main_menu.c
	add_gui_child(game->ui, map_editor_select);
	*is_loaded = TRUE;
=======
>>>>>>> 902071b0a5c1d877af5268d2c75fc4a7a48c2f63:src/init/init_main_menu.c
}
