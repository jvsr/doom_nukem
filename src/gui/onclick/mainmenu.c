/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mainmenu.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 17:02:43 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/15 17:02:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"
#include "gui_config.h"

void	mainmenu_missions(t_game *game, t_transform *gui)
{
	t_transform	*missions_menu;
	t_transform	*missions_overlay;
	t_transform	*missions_campaign;
	t_transform	*missions_custom;

	(void)gui;
	missions_menu = get_gui_child(game->ui, "missionsmenu");
	missions_overlay = get_gui_child(game->ui, "missionsoverlay");
	missions_campaign = get_gui_child(game->ui, "missionscampaignbutton");
	missions_custom = get_gui_child(game->ui, "missionscustombutton");
	set_elem_show_clickable(missions_menu, TRUE);
	set_elem_show_clickable(missions_overlay, TRUE);
	set_elem_show_clickable(missions_campaign, TRUE);
	set_elem_show_clickable(missions_custom, TRUE);
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
}

void	mainmenu_quit(t_game *game, t_transform *gui)
{
	(void)gui;
	quit(game);
}
