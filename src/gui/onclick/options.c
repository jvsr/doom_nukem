/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:27:39 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/16 14:27:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h" //

#include "gui.h"
#include "game.h"
#include "setting.h"
#include "onclick.h"
#include "gui_config.h"

void	incr_float_max(float *loc, float incr, float max)
{
	*loc += incr;
	if (*loc > max)
		*loc = max;
}

void	decr_float_min(float *loc, float decr, float min)
{
	*loc -= decr;
	if (*loc < min)
		*loc = min;
}

void	incr_uint16_max(t_uint16 *loc, t_uint16 incr, t_uint16 max)
{
	*loc += incr;
	if (*loc > max)
		*loc = max;
}

void	decr_uint16_min(t_uint16 *loc, t_uint16 decr, t_uint16 min)
{
	*loc -= decr;
	if (*loc < min)
		*loc = min;
}

void	options_sensitivity_up(t_game *game, t_transform *gui)
{
	incr_float_max(&game->setting->sensitivity, 0.1, 3.0);
	set_sensitivity(game->setting, gui->parent.elem);
}

void	options_sensitivity_down(t_game *game, t_transform *gui)
{
	decr_float_min(&game->setting->sensitivity, 0.1, 0.1);
	set_sensitivity(game->setting, gui->parent.elem);
}

void	options_volume_up(t_game *game, t_transform *gui)
{
	incr_float_max(&game->setting->volume, 0.1, 1.0);
	set_volume(game->setting, gui->parent.elem);
}

void	options_volume_down(t_game *game, t_transform *gui)
{
	decr_float_min(&game->setting->volume, 0.1, 0.0);
	set_volume(game->setting, gui->parent.elem);
}

void	options_fov_up(t_game *game, t_transform *gui)
{
	incr_uint16_max(&game->setting->fov, 5, 110);
	set_volume(game->setting, gui->parent.elem);
}

void	options_fov_down(t_game *game, t_transform *gui)
{
	decr_uint16_min(&game->setting->fov, 5, 45);
	set_volume(game->setting, gui->parent.elem);
}

void	options_return(t_game *game, t_transform *gui)
{
	(void)gui;
	del_elem_child(get_gui_child(game->ui, "mainmenu"), "options");
}
