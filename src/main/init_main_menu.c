/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_main_menu.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:28:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/22 18:29:04 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_thread.h>

#include "libft/ft_bool.h"

#include "gui.h"
#include "game.h"
#include "gui_config.h"

void	init_main_menu(t_game *game, t_bool *is_loaded)
{
	t_transform	*main_menu;
	t_transform	*options_menu;
	t_transform	*select_level;
	t_transform	*controls_menu;

	main_menu = analyze_gui_config(game->ui, "main_menu");
	options_menu = analyze_gui_config(game->ui, "options_menu");
	select_level = analyze_gui_config(game->ui, "select_level");
	controls_menu = analyze_gui_config(game->ui, "controls_menu");
	add_elem_child(options_menu, controls_menu);
	add_elem_child(main_menu, options_menu);
	add_elem_child(main_menu, select_level);
	add_gui_child(game->ui, main_menu);
	*is_loaded = TRUE;
}
