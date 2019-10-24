/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fov.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:38:49 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 13:57:26 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"

void	set_fov(t_setting *setting, t_transform *parent)
{
	set_int(setting->fov,
		get_elem_child(parent, "curfov"));
}

void	options_fov_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_uint16_max(&game->setting->fov, 5, 110);
	set_fov(game->setting, gui->parent.elem);
}

void	options_fov_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_uint16_min(&game->setting->fov, 5, 45);
	set_fov(game->setting, gui->parent.elem);
}
