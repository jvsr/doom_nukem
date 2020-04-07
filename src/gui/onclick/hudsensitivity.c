/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hudsensitivity.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:12:38 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:14:18 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"

void	set_hudsensitivity(t_setting *setting, t_transform *parent)
{
	set_float(setting->sensitivity,
		get_elem_child(parent, "curHudSensitivity"),
		1);
}

void	options_hud_sensitivity_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->sensitivity, 0.1, 3.0);
	set_hudsensitivity(game->setting, gui->parent.elem);
}

void	options_hud_sensitivity_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->sensitivity, 0.1, 0.1);
	set_hudsensitivity(game->setting, gui->parent.elem);
}
