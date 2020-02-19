/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fov.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:38:49 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/19 12:41:38 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"
#include "cmath.h"

void	set_fov(t_setting *setting, t_transform *parent, SDL_Surface *surf)
{
	set_int(setting->fov, get_elem_child(parent, "curfov"));
	setting->vfov = calc_vfov(setting->fov, surf->w, surf->h);
}

void	options_fov_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_uint16_max(&game->setting->fov, FOV_STEP, MAX_FOV);
	set_fov(game->setting, gui->parent.elem, game->surface);
}

void	options_fov_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_uint16_min(&game->setting->fov, FOV_STEP, MIN_FOV);
	set_fov(game->setting, gui->parent.elem, game->surface);
}

void	set_hudfov(t_setting *setting, t_transform *parent, SDL_Surface *surf)
{
	set_int(setting->fov, get_elem_child(parent, "curhudfov"));
	setting->vfov = calc_vfov(setting->fov, surf->w, surf->h);
}

void	options_hud_fov_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_uint16_max(&game->setting->fov, FOV_STEP, MAX_FOV);
	set_hudfov(game->setting, gui->parent.elem, game->surface);
}

void	options_hud_fov_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_uint16_min(&game->setting->fov, FOV_STEP, MIN_FOV);
	set_hudfov(game->setting, gui->parent.elem, game->surface);
}
