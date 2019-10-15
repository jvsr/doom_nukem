/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onclick_menu.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 17:02:43 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/15 17:02:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "gui_config.h"

void	button_menu_options(t_game *game, t_transform *gui)
{
	t_transform	*options_menu;

	(void)gui;
	options_menu = analyze_gui_config(game->ui, "options_menu");
	add_elem_child(get_gui_child(game->ui, "mainmenu"), options_menu);
}

void	button_menu_quit(t_game *game, t_transform *gui)
{
	(void)gui;
	quit(game);
}
