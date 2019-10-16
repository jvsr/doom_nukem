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
#include "gui_config.h"

static char	*get_resolutiontype(t_resolution_type resolution_type)
{
	if (resolution_type == windowed)
		return ("Windowed");
	else if (resolution_type == fullscreen)
		return ("Fullscreen");
	else
		return ("Borderless");
}

void		mainmenu_options(t_game *game, t_transform *gui)
{
	t_transform	*options_menu;

	(void)gui;
	options_menu = analyze_gui_config(game->ui, "options_menu");
	set_elem_text_str(get_elem_child(options_menu, "cursensitivity"),
		ft_strformat("%.1f", game->settings->sensitivity));
	set_elem_text_str(get_elem_child(options_menu, "curvolume"),
		ft_strformat("%.1f", game->settings->volume));
	set_elem_text_str(get_elem_child(options_menu, "curfov"),
		ft_strformat("%d", game->settings->fov));
	set_elem_text_str(get_elem_child(options_menu, "curresolution"),
		ft_strformat("%d x %d", game->settings->resolution.x,
			game->settings->resolution.y));
	set_elem_text_str(get_elem_child(options_menu, "curresolutiontype"),
		get_resolutiontype(game->settings->resolution_type));
	add_elem_child(get_gui_child(game->ui, "mainmenu"), options_menu);
}

void	mainmenu_quit(t_game *game, t_transform *gui)
{
	(void)gui;
	quit(game);
}
