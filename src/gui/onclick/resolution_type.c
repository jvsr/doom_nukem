/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resolution_type.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:45:36 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 15:50:52 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"

void		incr_game_resolution_type(t_resolution_type *resolution_type)
{
	if (*resolution_type == windowed)
		*resolution_type = borderless;
	else if (*resolution_type == borderless)
		*resolution_type = fullscreen;
	else if (*resolution_type == fullscreen)
		*resolution_type = windowed;
}

void		decr_game_resolution_type(t_resolution_type *resolution_type)
{
	if (*resolution_type == fullscreen)
		*resolution_type = borderless;
	else if (*resolution_type == borderless)
		*resolution_type = windowed;
	else if (*resolution_type == windowed)
		*resolution_type = fullscreen;
}

void		options_resolutiontype_up(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	incr_game_resolution_type(&game->setting->resolution_type);
	set_resolution_type(game->setting, gui->parent.elem);
}

void		options_resolutiontype_down(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	decr_game_resolution_type(&game->setting->resolution_type);
	set_resolution_type(game->setting, gui->parent.elem);
}
