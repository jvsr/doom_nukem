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

void		mainmenu_options(t_game *game, t_transform *gui)
{
	t_transform	*options_menu;
	t_transform	*options_overlay;

	options_menu = get_elem_child(gui->parent.elem, "optionsmenu");
	options_overlay = get_elem_child(gui->parent.elem, "optionsoverlay");
	set_elem_show_clickable(options_menu, TRUE);
	set_elem_show_clickable(options_overlay, TRUE);
	set_sensitivity(game->setting, options_menu);
	set_volume(game->setting, options_menu);
	set_fov(game->setting, options_menu);
	set_resolution(game->setting, options_menu);
	set_resolutiontype(game->setting, options_menu);
}

void	mainmenu_quit(t_game *game, t_transform *gui)
{
	(void)gui;
	quit(game);
}
