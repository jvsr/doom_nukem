/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sensitivity.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:48:02 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:57 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"

void	set_sensitivity(t_setting *setting, t_transform *parent)
{
	set_float(setting->sensitivity,
		get_elem_child(parent, "curSensitivity"),
		1);
}

void	options_sensitivity_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->sensitivity, 0.1, 3.0);
	set_sensitivity(game->setting, gui->parent.elem);
}

void	options_sensitivity_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->sensitivity, 0.1, 0.1);
	set_sensitivity(game->setting, gui->parent.elem);
}
