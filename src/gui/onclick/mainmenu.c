/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainmenu.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 17:02:43 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 13:52:52 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"
#include "gui_config.h"
#include "eventstate.h"

void	mainmenu_missions(t_game *game, t_transform *gui)
{
	t_transform	*elem;

	(void)gui;
	elem = get_gui_child(game->ui, "missionsmenu");
	set_elem_show_clickable(elem, TRUE);
	elem = get_gui_child(game->ui, "missionsoverlay");
	set_elem_show_clickable(elem, TRUE);
	elem = get_gui_child(game->ui, "missionscampaignbutton");
	set_elem_show_clickable(elem, TRUE);
	elem = get_gui_child(game->ui, "missionscustombutton");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = missions;
}

void	mainmenu_options(t_game *game, t_transform *gui)
{
	t_transform	*options_menu;
	t_transform	*options_overlay;

	(void)gui;
	options_menu = get_gui_child(game->ui, "optionsmenu");
	options_overlay = get_gui_child(game->ui, "optionsoverlay");
	set_elem_show_clickable(options_menu, TRUE);
	set_elem_show_clickable(options_overlay, TRUE);
	set_sensitivity(game->setting, options_menu);
	set_music(game->setting, options_menu);
	set_sound(game->setting, options_menu);
	set_fov(game->setting, options_menu);
	set_resolution(game->setting, options_menu);
	set_resolution_type(game->setting, options_menu);
	game->cureventstate->eventstate = options;
}

void	mainmenu_quit(t_game *game, t_transform *gui)
{
	(void)gui;
	(void)game;
	quit(0);
}
